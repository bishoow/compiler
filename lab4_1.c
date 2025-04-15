//Write a program in C to design finite automata that accepts all string with
//“ing” over ?a to z. (Example: “anything”, “something”, etc.).
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_LENGTH 100
bool isAcceptedByFA(const char *str) {
    int state = 0; // Start state
    char c;

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];

        // Transition based on the current state and input character
        switch (state) {
            case 0: // Start state
                if (c == 'i') 
                    state = 1;
                else 
                    state = 0;
                break;

            case 1: // After 'i'
                if (c == 'n') 
                    state = 2;
                else if (c == 'i') 
                    state = 1;
                else 
                    state = 0;
                break;

            case 2: // After 'in'
                if (c == 'g') 
                    state = 3;
                else if (c == 'i') 
                    state = 1;
                else 
                    state = 0;
                break;

            case 3: // Accept state (after "ing")
                state = 3; // Remain in the accept state
                break;

            default:
                state = 0; // Reset to start state for unexpected cases
                break;
        }
    }

    // Accept if the final state is the accepting state (3)
    return (state == 3);
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string (over the alphabet 'a' to 'z'): ");

    // Limit the input length to prevent buffer overflow
    if (scanf("%99s", input) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Validate and process the input
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalpha(input[i])) {
            printf("Invalid input! Please enter only alphabetic characters.\n");
            return 1;
        }
        input[i] = tolower(input[i]); // Convert to lowercase
    }

    // Check if the string is accepted by the FA
    if (isAcceptedByFA(input)) {
        printf("The string \"%s\" is accepted (contains 'ing').\n", input);
    } else {
        printf("The string \"%s\" is not accepted (does not contain 'ing').\n", input);
    }

    return 0;
}

