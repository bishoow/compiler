count no of words
$ flex filename.l
$ cc lex.yy.c -o (filename).l
 $ ./(filename).l

%{
#include <stdio.h>
int word_count = 0; // Variable to hold the word count
%}

%%
[a-zA-Z]+    { word_count++; }         // Match words (sequences of letters)
[ \t\n]+     { /* Ignore whitespace */ }
.            { /* Ignore other characters */ }
%%

int main() {
    printf("Enter text (Ctrl+D to end on Linux/Mac or Ctrl+Z then Enter on Windows):\n");
    yylex(); // Start scanning input
    printf("Number of words: %d\n", word_count);
    return 0;
}

int yywrap() {
    return 1; // Indicates the end of input
}

