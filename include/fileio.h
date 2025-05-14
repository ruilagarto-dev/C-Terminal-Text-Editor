/**
 * @file fileio.h
 * @author ruilagarto-dev
 * 
 * @brief 
 * [PT] Operações utilitárias para manipulação de arquivos.  
 * [EN] Utility operations for file handling.
 * 
 * @version 1.0
 * @date 2025-05-14
 */
#pragma once

/**
 * @brief
 * [PT] Enumeração de códigos de estado para operações de arquivo.  
 * [EN] Enumeration of status codes for file operations.
 */
typedef enum {
    FILEIO_SUCCESS = 0,      /**< [PT] Operação concluída com sucesso / [EN] Operation completed successfully */
    FILEIO_ERROR_OPEN,       /**< [PT] Falha ao abrir o arquivo / [EN] Failed to open file */
    FILEIO_ERROR_READ,       /**< [PT] Falha ao ler o arquivo / [EN] Failed to read file */
    FILEIO_ERROR_WRITE,      /**< [PT] Falha ao escrever no arquivo / [EN] Failed to write to file */
    FILEIO_ERROR_UNKNOWN     /**< [PT] Erro desconhecido / [EN] Unknown error */
} FileIOStatus;


/**
 * @brief
 * [PT] Verifica se um arquivo existe.  
 * [EN] Checks if a file exists.
 *
 * @param filename 
 * [PT/EN] Caminho para o arquivo / Path to the file.
 *
 * @return 
 * [PT] `FILEIO_SUCCESS` se existir, `FILEIO_ERROR_OPEN` caso contrário.  
 * [EN] `FILEIO_SUCCESS` if it exists, `FILEIO_ERROR_OPEN` otherwise.
 */
FileIOStatus doesFileExists(char filename[]);

/**
 * @brief
 * [PT] Retorna o tamanho de um arquivo em bytes.  
 * [EN] Returns the file size in bytes.
 *
 * @param fileName 
 * [PT/EN] Caminho para o arquivo / Path to the file.
 *
 * @return 
 * [PT] Tamanho do arquivo em bytes ou -1 em caso de erro.  
 * [EN] File size in bytes or -1 on error.
 */
int getFileSize(char fileName[]);

/**
 * @brief
 * [PT] Remove todo o conteúdo de um arquivo.  
 * [EN] Clears the contents of a file.
 *
 * @param fileName 
 * [PT/EN] Caminho para o arquivo / Path to the file.
 *
 * @return 
 * [PT/EN] `FILEIO_SUCCESS` se for bem-sucedido / if successful; `FILEIO_ERROR_OPEN` caso contrário / otherwise.
 */
FileIOStatus clearFileContents(char fileName[]);


/**
 * @brief
 * [PT] Lê o conteúdo de um arquivo para um buffer.  
 * [EN] Reads file content into a buffer.
 *
 * @param fileName 
 * [PT/EN] Caminho para o arquivo / Path to the file.
 * @param buffer 
 * [PT/EN] Buffer de destino / Destination buffer.
 * @param bufferSize 
 * [PT/EN] Tamanho máximo do buffer / Maximum buffer size.
 *
 * @return 
 * [PT/EN] `FILEIO_SUCCESS` se a leitura for bem-sucedida / if successful; `FILEIO_ERROR_OPEN` caso contrário / otherwise.
 */
FileIOStatus readTextFromFile(char fileName[], char *buffer, int bufferSize);



/**
 * @brief
 * [PT] Escreve uma string no final de um arquivo.  
 * [EN] Appends a string to the end of a file.
 *
 * @param fileName 
 * [PT/EN] Caminho para o arquivo / Path to the file.
 * @param content 
 * [PT/EN] Conteúdo a ser escrito / Content to write.
 * @param appendNewLine 
 * [PT] Adiciona `\n` após o conteúdo se verdadeiro / [EN] Adds `\n` after content if true.
 *
 * @return 
 * [PT/EN] `FILEIO_SUCCESS` se for bem-sucedido / if successful;  
 *         `FILEIO_ERROR_OPEN` se falhar ao abrir / if unable to open;  
 *         `FILEIO_ERROR_WRITE` se falhar ao escrever / if write fails.
 */
FileIOStatus writeTextToFile(char fileName[], char content[], bool appendNewLine);