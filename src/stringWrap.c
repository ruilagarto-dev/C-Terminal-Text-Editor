/**
 * @file stringWrap.c
 * @author ruilagarto-dev
 * 
 * @brief 
 * [PT/EN] Implementação da manipulação de strings com comprimento fixo / Implementation of fixed-length string manipulation
 * 
 * @version 1.0
 * @date 2025-05-14
 */

#include "stringWrap.h"
#include <string.h>

/**
 * @brief 
 * [PT/EN] Cria uma instância de StringWrap a partir de uma string fornecida / Creates a StringWrap instance from a given string
 * 
 * [PT] Esta função copia a string fornecida para a struct StringWrap. Caso a string fornecida seja maior que o tamanho máximo permitido, ela será truncada.
 * 
 * [EN] This function copies the provided string into the StringWrap struct. 
 * If the given string is larger than the allowed maximum size, it will be truncated.
 * 
 * @param str 
 * [PT/EN] A string que será armazenada na struct / The string to be stored in the struct
 * 
 * @return 
 * [PT/EN] Uma instância de StringWrap com a string fornecida / A StringWrap instance with the given string
 */
StringWrap stringWrapCreate(char *str){
    StringWrap strW;
    strcpy(strW.text, str);
    return strW;
}