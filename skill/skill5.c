#include <stdio.h>
#include <string.h>

int main() {
    char input[200];

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("\nOriginal Input:\n%s\n", input);

    printf("\nParsing quotes...\n");

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\'') {
            printf("Single quote found at position %d\n", i);
        }
        else if (input[i] == '"') {
            printf("Double quote found at position %d\n", i);
        }
    }

    return 0;
}
