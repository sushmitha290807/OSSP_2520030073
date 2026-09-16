#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char input[200];
    char previous[PATH_MAX] = "";

    while (1) {
        char current[PATH_MAX];

        getcwd(current, sizeof(current));
        printf("%s$ ", current);

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // Exit
        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        // cd command
        if (strncmp(input, "cd ", 3) == 0) {
            char *path = input + 3;

            // Save current directory
            strcpy(previous, current);

            if (chdir(path) == -1) {
                perror("cd failed");
            } else {
                printf("Directory changed successfully.\n");
            }
        }

        // cd -
        else if (strcmp(input, "cd -") == 0) {
            if (strlen(previous) == 0) {
                printf("Previous directory not available.\n");
            } else {
                char temp[PATH_MAX];

                strcpy(temp, current);

                if (chdir(previous) == -1) {
                    perror("cd failed");
                } else {
                    strcpy(previous, temp);
                    printf("Changed to previous directory.\n");
                }
            }
        }

        else {
            printf("Unknown command: %s\n", input);
        }
    }

    return 0;
}
