1. Write a lex program to find if given letter is vowel or consonants.
%{
#include <stdio.h>
%}

%%
[aAeEiIoOuU]            { printf("%s is a vowel\n", yytext); }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]  { printf("%s is a consonant\n", yytext); }
[^a-zA-Z]               { printf("%s is not a valid letter\n", yytext); }
%%

int main() {
    printf("Enter a character: ");
    yylex();  // Run the lexical analyzer
    return 0;
}

int yywrap() {
    return 1; // Signal end of input
}

