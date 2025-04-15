LAB 2: Write a flex program to identify keywords, numbers, operators and
identifiers.
$ flex filename.l
$ cc lex.yy.c -o (filename).l
 $ ./(filename).l
%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_KEYWORDS 10

char *keywords[] = {
    "int", "float", "if", "else", "while",
    "for", "return", "void", "char", "double"
};

int isKeyword(const char *str) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
%}

%%

[a-zA-Z_][a-zA-Z0-9_]* {
    if (isKeyword(yytext)) {
        printf("Keyword: %s\n", yytext);
    } else {
        printf("Identifier: %s\n", yytext);
    }
}

[0-9]+(\.[0-9]+)? {
    printf("Number: %s\n", yytext);
}

[+\-*/=<>&|!]+ {
    printf("Operator: %s\n", yytext);
}

[ \t\n]+    ; // Ignore whitespace

. {
    printf("Unknown character: %s\n", yytext);
}
%%

int main(int argc, char *argv[]) {
    printf("Enter the input (press Ctrl+D to finish on Linux/Mac or Ctrl+Z on Windows):\n");
    yylex(); // Start scanning input
    return 0;
}

int yywrap() {
    return 1; // End of input
}

