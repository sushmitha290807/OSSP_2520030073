#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];

    while (1) {
        printf("myshell> ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        // Exit built-in command
        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        // pwd built-in command
        if (strcmp(input, "pwd") == 0) {
            char *pwd = getenv("PWD");

            if (pwd != NULL)
                printf("%s\n", pwd);
            else
                printf("PWD variable not found.\n");

            continue;
        }

        // Variable expansion: echo $VARIABLE
        if (strncmp(input, "echo $", 6) == 0) {
            char *variable = input + 6;
            char *value = getenv(variable);

            if (value != NULL)
                printf("%s\n", value);
            else
                printf("Undefined variable: %s\n", variable);

            continue;
        }

        printf("Unknown command: %s\n", input);
    }

    return 0;
}
