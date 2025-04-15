#include <stdio.h>
#include <string.h>
#include <ctype.h>
int n;
char a[10][10];
char result[20];
void follow(char c);
void first(char c, char *res);
void addToResultSet(char *res, char val);
int main() {
    int i;
    char c, choice;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter %d productions.\nEach production should be in the format A=... or A->...\n", n);

    for (i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    do {
        printf("Find FOLLOW of: ");
        scanf(" %c", &c);
        memset(result, 0, sizeof(result));
        follow(c);
        printf("FOLLOW(%c) = { ", c);
        for (i = 0; result[i] != '\0'; i++)
            printf("%c ", result[i]);
        printf("}\n");

        printf("Do you want to continue (y/n)?: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void follow(char c) {
    int i, j;
    char tempRes[20];

    if (a[0][0] == c)  // Start symbol
        addToResultSet(result, '$');

    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0') {
                    memset(tempRes, 0, sizeof(tempRes));
                    first(a[i][j + 1], tempRes);
                    for (int k = 0; tempRes[k] != '\0'; k++) {
                        if (tempRes[k] != '#')  // ignore epsilon
                            addToResultSet(result, tempRes[k]);
                        else if (a[i][j + 1] == '\0' || tempRes[k] == '#') {
                            if (a[i][0] != c)
                                follow(a[i][0]);
                        }
                    }
                } else {
                    if (a[i][0] != c)
                        follow(a[i][0]);
                }
            }
        }
    }
}

void first(char c, char *res) {
    char tempRes[20];
    int k;
    if (!isupper(c)) {
        addToResultSet(res, c);
        return;
    }

    for (k = 0; k < n; k++) {
        if (a[k][0] == c) {
            if (a[k][2] == '#') {
                addToResultSet(res, '#');
            } else if (!isupper(a[k][2])) {
                addToResultSet(res, a[k][2]);
            } else {
                memset(tempRes, 0, sizeof(tempRes));
                first(a[k][2], tempRes);
                for (int j = 0; tempRes[j] != '\0'; j++)
                    addToResultSet(res, tempRes[j]);
            }
        }
    }
}

void addToResultSet(char *res, char val) {
    for (int i = 0; res[i] != '\0'; i++) {
        if (res[i] == val)
            return;
    }
    int len = strlen(res);
    res[len] = val;
    res[len + 1] = '\0';
}

