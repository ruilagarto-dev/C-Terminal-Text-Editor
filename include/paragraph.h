#pragma once

#include "token.h"

#include <stdbool.h>


typedef struct paragraph{
    int numberTokens;
    Token *tokens;
}Paragraph;


Paragraph createParagraph(char text[]);
void freeParagraph(Paragraph *p);
int replaceWord(Paragraph p, char target[], char replacement[]);
void printParagraph(Paragraph p);
void printParagraphToBuffer(Paragraph p, char* buffer, int bufferSize);
