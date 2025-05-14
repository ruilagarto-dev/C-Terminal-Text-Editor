/**
 * @file fileio.c
 * @author ruilagarto-dev
 * 
 * @brief 
 * [PT] Implementação das operações utilitárias para manipulação de arquivos.  
 * [EN] Implementation of utility operations for file manipulation.
 * 
 * @version 1.0
 * @date 2025-05-14
 */

#include "fileio.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


/**
 * @brief 
 * [PT] Verifica se um arquivo existe no sistema de arquivos.  
 * [EN] Checks if a file exists in the filesystem.
 * 
 * @param filename 
 * [PT/EN] Caminho do arquivo / File path.
 * 
 * @return 
 * [PT] `FILEIO_SUCCESS` se o arquivo existir, `FILEIO_ERROR_OPEN` caso contrário.  
 * [EN] `FILEIO_SUCCESS` if the file exists, `FILEIO_ERROR_OPEN` otherwise.
 */
FileIOStatus doesFileExists(char filename[]){
    struct stat buffer;
    return (stat(fileName, &buffer) == 0) ? FILEIO_SUCCESS : FILEIO_ERROR_OPEN;
}


/**
 * @brief 
 * [PT] Retorna o tamanho do arquivo em bytes.  
 * [EN] Returns the file size in bytes.
 * 
 * @param fileName 
 * [PT/EN] Caminho do arquivo / File path.
 * 
 * @return 
 * [PT] Tamanho do arquivo em bytes, ou -1 em caso de erro.  
 * [EN] Size of the file in bytes, or -1 on error.
 */
int getFileSize(char fileName[]) {
    FILE *file = fopen(fileName, "r");
    if (!file) return -1;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return (size == -1) ? -1 : size;
}

/**
 * @brief 
 * [PT] Apaga todo o conteúdo de um arquivo abrindo-o em modo de escrita.  
 * [EN] Clears the content of a file by opening it in write mode.
 * 
 * @param fileName 
 * [PT/EN] Caminho do arquivo / File path.
 * 
 * @return 
 * [PT/EN] `FILEIO_SUCCESS` se o arquivo for limpo com sucesso, `FILEIO_ERROR_OPEN` se falhar ao abrir.  
 *         `FILEIO_SUCCESS` on success, `FILEIO_ERROR_OPEN` if failed to open.
 */
FileIOStatus clearFileContents(char fileName[]){
    FILE *file = fopen(fileName, "w");
    if(!file) return FILEIO_ERROR_OPEN;

    fclose(file);

    return FILEIO_SUCCESS;
}


/**
 * @brief 
 * [PT] Lê o conteúdo de um arquivo para o buffer especificado.  
 * [EN] Reads the content of a file into the specified buffer.
 * 
 * @param fileName 
 * [PT/EN] Caminho do arquivo / File path.
 * @param buffer 
 * [PT/EN] Buffer para armazenar o conteúdo lido / Buffer to store read content.
 * @param bufferSize 
 * [PT/EN] Tamanho máximo do buffer / Maximum size of the buffer.
 * 
 * @return 
 * [PT/EN] `FILEIO_SUCCESS` se a leitura for bem-sucedida, `FILEIO_ERROR_OPEN` caso contrário.  
 *         `FILEIO_SUCCESS` on success, `FILEIO_ERROR_OPEN` otherwise.
 */
FileIOStatus readTextFromFile(char fileName[], char *buffer, int bufferSize){
    FILE *file = fopen(fileName, "r");
    if (!file) return FILEIO_ERROR_OPEN;

    size_t read = fread(buffer, sizeof(char), bufferSize - 1, file);  // Reservar espaço para '\0'
    buffer[read] = '\0'; // Garantir string terminada

    fclose(file);
    return FILEIO_SUCCESS;
}

/**
 * @brief 
 * [PT] Escreve texto no final de um arquivo. Pode adicionar uma quebra de linha.  
 * [EN] Writes text to the end of a file, optionally adding a newline.
 * 
 * @param fileName 
 * [PT/EN] Caminho do arquivo / File path.
 * @param content 
 * [PT/EN] Conteúdo a ser escrito / Content to be written.
 * @param appendNewLine 
 * [PT] Se verdadeiro, adiciona uma nova linha após o conteúdo / [EN] If true, adds a newline after the content.
 * 
 * @return 
 * [PT/EN] `FILEIO_SUCCESS` em caso de sucesso, `FILEIO_ERROR_OPEN` se não conseguir abrir,  
 *         `FILEIO_ERROR_WRITE` se a escrita falhar.  
 *         `FILEIO_SUCCESS` on success, `FILEIO_ERROR_OPEN` if unable to open,  
 *         `FILEIO_ERROR_WRITE` if writing fails.
 */
FileIOStatus writeTextToFile(char fileName[], char content[], bool appendNewLine){
    FILE *file = fopen(fileName, "a");
    if (!file) return FILEIO_ERROR_OPEN;

    int result = appendNewLine ? fprintf(file, "%s\n", content) : fprintf(file, "%s", content);

    fclose(file);
    return (result < 0) ? FILEIO_ERROR_WRITE  : FILEIO_SUCCESS;
}