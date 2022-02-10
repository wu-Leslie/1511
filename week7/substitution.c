//substitution.c
//Leslie z5339245

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 26

int encrypt(int character, int letter_array[ARRAY_SIZE]);

int main(int argc, char *argv[]) {
    int argument = 1;
    int letter_array[ARRAY_SIZE] = {0};
    int x = 0;

    while (x < 26) {
        letter_array[x] = argv[argument][x];
        x++;
    }

    int character = getchar();
    while (character != EOF) {

        int new_character = encrypt(character, letter_array);
        putchar(new_character);

        character = getchar();
    }

    return 0;
}

int encrypt(int character, int letter_array[ARRAY_SIZE]) {
    if (character >= 'a' && character <= 'z') {
        character = character - 97;
        return letter_array[character];
    } else if (character >= 'A' && character <= 'Z') {
        character = character - 65;
        return letter_array[character] - 32;
    } else {
        return character;
    }

}










