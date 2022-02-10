//decode.c
//Leslie z5339245

#include <stdio.h>

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
    int x = 0;
    if (character >= 'a' && character <= 'z') {
        while (x < 26) {
            if (character == letter_array[x]) {
                break;
            }
            x++;
        }
        return 97 + x;

    } else if (character >= 'A' && character <= 'Z') {
        while (x < 26) {
            if (character+32 == letter_array[x]) {
                break;
            }
            x++;
        }
        return 65 + x;

    } else {
        return character;
    }
}










