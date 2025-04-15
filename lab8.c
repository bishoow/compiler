//Write a program in C to implement Intermediate Code
// a=b+c*d
generation.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
char str[MAX], left[15], right[15];
int tmpch = 'Z'; // Temp variable names: Z, Y, X...
struct exp {
    int pos;
    char op;
} k[15];

int numOperators = 0;

void findopr();
void explore();
void fleft(int);
void fright(int);

int main() {
    printf("Input: ");
    scanf("%s", str);
    printf("The intermediate code:\n");
    findopr();
    explore();
    return 0;
}

void findopr() {
    const char ops[] = { '/', '*', '+', '-' };
    for (int p = 0; p < 4; p++) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == ops[p]) {
                k[numOperators].pos = i;
                k[numOperators++].op = ops[p];
            }
        }
    }
}

void explore() {
    for (int i = 0; i < numOperators; i++) {
        fleft(k[i].pos);
        fright(k[i].pos);
        str[k[i].pos] = tmpch; // Replace operator with temp variable
        printf("\t%c = %s %c %s\n", tmpch--, left, k[i].op, right);
    }

    // Final assignment (assumes format: a=...)
    char result[2] = { str[0], '\0' };
    fright(1);
    printf("\t%s = %s\n", result, right);
}

void fleft(int pos) {
    int i = pos - 1, start = i;

    while (i >= 0 && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '=')
        i--;

    int len = start - i;
    strncpy(left, &str[i + 1], len);
    left[len] = '\0';

    // Mark used
    for (int j = i + 1; j <= start; j++)
        str[j] = '$';
}

void fright(int pos) {
    int i = pos + 1, start = i;

    while (str[i] != '\0' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '=')
        i++;

    int len = i - start;
    strncpy(right, &str[start], len);
    right[len] = '\0';

    // Mark used
    for (int j = start; j < i; j++)
        str[j] = '$';
}

