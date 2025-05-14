/**
 * @file token.h
 * @author ruilagarto-dev
 * @brief 
 * [PT/EN] Definições para manipulação de tokens com tipo e conteúdo / Definitions for handling tokens with type and content.
 * 
 * @version 1.0
 * @date 2025-05-15
 */

#pragma once

#include "stringWrap.h"


/**
 * @enum Type
 * @brief Enumeração para tipos de tokens.
 */
typedef enum{
    WORD = 1,           /**< Palavra (letras e acentuados) */
    PUNCTUATION = 2,    /**< Pontuação */
    SPACE = 3,          /**< Espaço em branco */
    INVALID = -1        /**< Token inválido */
} Type;


/**
 * @struct Token
 * @brief Representa um token com seu tipo e conteúdo.
 */
typedef struct token{
    Type type;              
    StringWrap content; 
} Token;


/**
 * @brief Cria um token a partir de uma string de conteúdo.
 * 
 * @param content String contendo o texto do token.
 * @return Token struct inicializada com o conteúdo e tipo identificado.
 */
Token createToken(char content[]);
