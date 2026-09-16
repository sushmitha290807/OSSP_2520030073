#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char input[200];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // pwd command
        if (strcmp(input, "pwd") == 0) {
            char cwd[PATH_MAX];

            if (getcwd(cwd, sizeof(cwd)) != NULL)
                printf("%s\n", cwd);
            else
                perror("getcwd");
        }

        // export command
        else if (strncmp(input, "export ", 7) == 0) {
            char *variable = input + 7;

            if (putenv(variable) == 0)
                printf("Variable exported successfully.\n");
            else
                perror("export");
        }

        // exit command
        else if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        else if (strlen(input) == 0) {
            continue;
        }

        else {
            printf("Unknown command: %s\n", input);
        }
    }

    return 0;
}
