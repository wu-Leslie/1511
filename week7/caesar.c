//string_to_lower_args.c
//Leslie z5339245
// / June 2021

#include <stdio.h>
#include <stdlib.h>

int encrypt(int character, int shift);

int main(int argc, char *argv[]) {
    int argument = 1;
    int n = atoi(argv[argument]);

    n %= 26;

    int character = getchar();
    while (character != EOF) {

        int new_character = encrypt(character, n);
        putchar(new_character);

        character = getchar();
    }

    return 0;
}

int encrypt(int character, int shift) {
    if (character >= 'a' && character <= 'z') {
        if (character + shift > 122) {
            character = character + shift - 122 + 96;
        } else if (character + shift < 97) {
            character = character + shift + 122 - 96;
        } else {
            character = character + shift;
        }
    } else if (character >= 'A' && character <= 'Z') {
        if (character + shift > 90) {
            character = character + shift - 90 + 64;
        } else if (character + shift < 65) {
            character = character + shift + 90 - 64;
        } else {
            character = character + shift;
        }
    }

    return character;
}










