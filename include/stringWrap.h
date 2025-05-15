/**
 * @file stringWrap.h
 * @author ruilagarto-dev
 * 
 * @brief 
 * [PT/EN] Manipulação de strings com comprimento fixo / Fixed length string manipulation
 * 
 * @version 1.0
 * @date 2025-05-14
 */
#pragma once

#define STRING_MAX_LEN 5000     

/**
 * @brief 
 * [PT/EN] Struct que representa uma string com tamanho fixo / Struct representing a fixed-length string
 */
typedef struct stringWrap{
    char text[STRING_MAX_LEN];
}StringWrap;

/**
 * @brief [PT/EN] Cria uma instância de StringWrap a partir de uma string fornecida / Creates a StringWrap instance from a given string
 * 
 * [PT] A função copia a string fornecida para a struct StringWrap, truncando ou ajustando conforme o comprimento máximo.
 * 
 * [EN] The function copies the provided string into the StringWrap struct, truncating or adjusting according to the maximum length.
 * 
 * @param sw [PT/EN] A string que será armazenada na struct / The string to be stored in the struct
 * @return [PT/EN] Uma instância de StringWrap com a string fornecida / A StringWrap instance with the given string
 */
StringWrap stringWrapCreate(char *sw);

/**
 * @brief 
 * [PT] Converte todos os caracteres da string em maiúsculas (in-place).  
 * [EN] Converts all characters in the string to uppercase (in-place).
 * 
 * [PT] Esta função modifica diretamente o conteúdo da instância `StringWrap`, 
 * convertendo todas as letras para maiúsculas. Caracteres não alfabéticos permanecem inalterados.
 * 
 * [EN] This function directly modifies the content of the `StringWrap` instance, 
 * converting all letters to uppercase. Non-alphabetic characters remain unchanged.
 * 
 * @param sw [PT/EN] Ponteiro para a struct `StringWrap` a ser modificada / Pointer to the `StringWrap` struct to be modified
 */
void sw_toUpper(StringWrap *sw);


/**
 * @brief 
 * [PT] Converte todos os caracteres da string em minúsculas (in-place).  
 * [EN] Converts all characters in the string to lowercase (in-place).
 * 
 * [PT] Esta função altera diretamente o conteúdo da instância `StringWrap`, 
 * transformando todas as letras maiúsculas em minúsculas. Caracteres não alfabéticos não são afetados.
 * 
 * [EN] This function directly changes the content of the `StringWrap` instance, 
 * converting all uppercase letters to lowercase. Non-alphabetic characters are not affected.
 * 
 * @param sw [PT/EN] Ponteiro para a struct `StringWrap` a ser modificada / Pointer to the `StringWrap` struct to be modified
 */
void sw_toLower(StringWrap *sw);