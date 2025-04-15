2. Write a lex program to count the number of vowels or
consonants in a given string.
%{
#include <stdio.h>

int vowels = 0;
int consonants = 0;
%}

%%
[aeiouAEIOU]         { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonants++; }
.                    ;
%%

int main() {
    printf("Enter a string: ");
    yylex();

    printf("\nNumber of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}

int yywrap() {
    return 1;
}

