//Write a program in C to design finite automata that accepts all string with
//“ing” over ?a to z. (Example: “anything”, “something”, etc.).
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isCComment(const char *line) {
    // Skip leading whitespace
    while (*line == ' ' || *line == '\t') {
        line++;
    }

    // Check for single-line comment (//)
    if (line[0] == '/' && line[1] == '/') {
        return true; // Single-line comment
    }

    // Check for multi-line comment (/* ... */)
    if (line[0] == '/' && line[1] == '*') {
        size_t len = strlen(line);
        // Check if it ends with "*/"
        if (len >= 4 && line[len - 2] == '*' && line[len - 1] == '/') {
            return true;
        }
    }

    return false; // Not a valid C comment
}

int main() {
    char line[256];

    printf("Enter a C comment: ");
    fgets(line, sizeof(line), stdin);

    // Remove newline character if present
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    if (isCComment(line)) {
        printf("Valid C comment.\n");
    } else {
        printf("Invalid input. Please enter a valid C comment.\n");
    }

    return 0;
}

