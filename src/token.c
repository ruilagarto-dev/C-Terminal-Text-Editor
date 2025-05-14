/**
 * @file token.c
 * @author ruilagarto-dev
 * @brief Implementação da manipulação de tokens.
 * 
 * @version 1.0
 * @date 2025-05-15
 */

#include "token.h"


#include <ctype.h>
#include <string.h>
#include <stdbool.h>


/**
 * @brief Verifica se um caractere é acentuado (códigos ASCII estendidos).
 * 
 * @param c Caractere a ser verificado.
 * @return true Se for um caractere acentuado.
 * @return false Caso contrário.
 */
static bool isAcentuado(char c);

/**
 * @brief Identifica o tipo de token baseado no conteúdo.
 * 
 * @param tk Token cujo conteúdo será analisado.
 * @return Type Tipo do token identificado (WORD, PUNCTUATION, SPACE ou INVALID).
 */
static Type identifyTokenType(Token tk);


Token createToken(char content[]){
    Token token;
    token.content = stringWrapCreate(content);
    token.type = identifyTokenType(token);
    return token;
}



static Type identifyTokenType(Token tk){
    int sizeContent = strlen(t.content.text);

    int wordFlag = 0;
    int spaceFlag = 0;
    int punctuationFlag = 0;

    for(int i = 0; i < sizeContent; i++){
        if(isAcentuado(tk.content.text[i])) wordFlag = 1;
        if(isalpha(tk.content.text[i])) wordFlag = 1;
        if(ispunct(tk.content.text[i])) punctuationFlag = 1;
        if(isspace(tk.content.text[i])) spaceFlag = 1;
    }

    if(wordFlag)return WORD;
    if(punctuationFlag)return PUNCTUATION;
    if(spaceFlag)return SPACE;
    return INVALID;
}


static bool isAcentuado(char c){
    unsigned char charCode = (unsigned char)c;
    return (charCode >= 192 && charCode <= 255);
}