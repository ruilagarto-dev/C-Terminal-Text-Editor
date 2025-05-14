#include "paragraph.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "utils.h"

#define MAX_LINE 1000

static int countWhiteSpace(char text[]) {
    int numWhitespaces = 0;

    int totalChars = strlen(text);
    
    for (int i = 0; i < totalChars; i++) {
        if (isspace(text[i])) numWhitespaces++;
    }
    return numWhitespaces;
}

static void printParagraphAlignedLeft(Paragraph p){
    for(int i=0;i < p.numberTokens; i++){
        printf("%s",p.tokens[i].content);
    }
}

void printParagraphToBuffer(Paragraph p, char* buffer, int bufferSize) {
    if (buffer == NULL || bufferSize <= 0) return;
    
    int pos = 0;
    for (int i = 0; i < p.numberTokens && pos < bufferSize - 1; i++) {
        int len = snprintf(buffer + pos, bufferSize - pos, "%s", p.tokens[i].content);
        if (len > 0) {
            pos += len;
        }
    }
}


static int *getWhiteSpacePositions(char text[], int numWhitespaces) {
    if(numWhitespaces == 0) return NULL;

    int *spacePos = (int *)malloc(numWhitespaces * sizeof(int));
    if(!spacePos){
        alertWarning("Memory allocation failed for whitespace positions.\n", "red");
        return NULL;
    }
    if(!spacePos) return NULL;

    int pos = 0;

    for (int i = 0; text[i]; i++) {
        if (isspace(text[i])) {
            spacePos[pos++] = i;
        }
    }
    return spacePos;
}


Paragraph createParagraph(char text[]){
    Paragraph p = {0, NULL};

    int numSpaces = countWhiteSpace(text);
    int *spacePositions = getWhiteSpacePositions(text, numSpaces);

    int numWords = numSpaces + 1;
    p.numberTokens = numSpaces + numWords;


    char **slices = sliceParagraph(text, &p.numberTokens);
    if(!slices){
        free(spacePositions);
        return p;
    }
    
    p.tokens = malloc(p.numberTokens * sizeof(Token));
    if(!p.tokens){
        alertWarning("Memory allocation failed for tokens.\n", "red");
        for(int i = 0; i < p.numberTokens; i++) {
            free(slices[i]);
        }
        free(slices);
        free(spacePositions);
        return p;
    }

    for(int i = 0; i<p.numberTokens; i++){
        p.tokens[i] = createToken(slices[i]);
        free(slices[i]);
    }

    free(slices);
    free(spacePositions);
    return p;
}



int countWithoutSpecialChar(char text[]){
    if(text == NULL) return 0;

    int size = strlen(text);
    int count = 0;

    for(int i = 0; i < size; i++){
        if(isalnum((unsigned char)text[i])) count++;
    }
    return count;
}


char **sliceParagraph(char text[], int *numTokens) {
    int numSpaces = countWhiteSpace(text);
    int *spacePositions = getWhiteSpacePositions(text, numSpaces);
    
    // Estimar o número máximo de tokens (cada caractere pode ser um token no pior caso)
    int maxTokens = strlen(text) * 2;
    char **tokens = (char **)malloc(maxTokens * sizeof(char *));
    if (!tokens) {
        free(spacePositions);
        return NULL;
    }

    int tokenIndex = 0;
    int currentPos = 0;
    int length = strlen(text);

    while (currentPos < length) {
        // Pular espaços em branco ou Verificar se é pontuação
        if(isspace(text[currentPos]) || ispunct(text[currentPos])){
            tokens[tokenIndex] = (char *)malloc(2);
            tokens[tokenIndex][0] = text[currentPos];
            tokens[tokenIndex][1] = '\0';
            tokenIndex++;
            currentPos++;
            continue;
        }

        // Se não for espaço nem pontuação, é parte de uma palavra
        int start = currentPos;
        while (currentPos < length && !isspace(text[currentPos]) && !ispunct(text[currentPos])) {
            currentPos++;
        }
        
        int wordLength = currentPos - start;
        if (wordLength > 0) {
            tokens[tokenIndex] = (char *)malloc(wordLength + 1);
            strncpy(tokens[tokenIndex], text + start, wordLength);
            tokens[tokenIndex][wordLength] = '\0';
            tokenIndex++;
        }
    }

    // Redimensionar o array de tokens para o tamanho real
    char **finalTokens = (char **)realloc(tokens, tokenIndex * sizeof(char *));
    if (!finalTokens) {
        for (int i = 0; i < tokenIndex; i++) free(tokens[i]);
        free(tokens);
        free(spacePositions);
        return NULL;
    }

    *numTokens = tokenIndex;
    free(spacePositions);
    return finalTokens;
}

int replaceWord(Paragraph p, char target[], char replacement[]){
    int occurrences = 0;
    for(int i = 0; i < p.numberTokens; i++){
        if(strcmp(p.tokens[i].content, target) == 0){
            strcpy(p.tokens[i].content, replacement); 
            occurrences++;
        }
    }
    return occurrences;
}

void printParagraph(Paragraph p){
    printParagraphAlignedLeft(p); 
}

void freeParagraph(Paragraph *p) {
    if(p == NULL || p->tokens == NULL){
        return;
    } 

    free(p->tokens);
    p->tokens = NULL;
    p->numberTokens = 0;   
}