//string_to_lower_args.c
//Leslie z5339245
// / June 2021

#include <stdio.h>
#include <string.h>
int string_to_lower_args(int character);

int main(int argc, char *argv[]) {
    int i = 1;
    int j;

    while (i < argc) {
        j = 0;
        while (j < strlen(argv[i])) {
            int new_character = string_to_lower_args(argv[i][j]);
            printf("%c", new_character);
            j++;
        }
        printf(" ");
        i++;
    }
    printf("\n");
    return 0;
}

int string_to_lower_args(int character) {
    if (character >= 'A' && character <= 'Z') {
        return character + 32;
    } else {
        return character;
    }
}









