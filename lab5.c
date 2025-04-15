//Write a program in C to implement Shift-reduce parsing.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Stack to store the parsed symbols
char stack[MAX][10];
int top = -1;

// Push operation for the stack
void push(char *str) {
    strcpy(stack[++top], str);
}

// Pop operation for the stack
void pop() {
    if (top >= 0) {
        top--;
    }
}

// Display the current stack content
void displayStack() {
    for (int i = 0; i <= top; i++) {
        printf("%s", stack[i]);
    }
}

// Function to check for reductions
int reduce() {
    if (top >= 2) {
        // Check for E + E or E * E
        if ((strcmp(stack[top - 2], "E") == 0) &&
            (strcmp(stack[top - 1], "+") == 0 || strcmp(stack[top - 1], "*") == 0) &&
            (strcmp(stack[top], "E") == 0)) {

            // Reduce E + E or E * E to E
            pop();
            pop();
            pop();
            push("E");
            return 1;
        }
    }
    if (top >= 0) {
        // Check for id -> E
        if (strcmp(stack[top], "id") == 0) {
            // Reduce id to E
            pop();
            push("E");
            return 1;
        }
    }
    return 0;
}

// Shift-Reduce Parsing Function
void shiftReduceParsing(char input[]) {
    char *token = strtok(input, " ");

    while (token != NULL) {
        // Shift operation
        push(token);
        printf("Shift: ");
        displayStack();
        printf("\n");

        // Perform reductions
        while (reduce()) {
            printf("Reduce: ");
            displayStack();
            printf("\n");
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Final result
    if (top == 0 && strcmp(stack[top], "E") == 0) {
        printf("Input string is successfully parsed!\n");
    } else {
        printf("Error: Input string cannot be parsed.\n");
    }
}

// Main Function
int main() {
    char input[MAX];

    printf("Enter the input string (tokens separated by spaces, e.g., id + id * id): ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    printf("\nPerforming Shift-Reduce Parsing:\n");
    shiftReduceParsing(input);

    return 0;
}

