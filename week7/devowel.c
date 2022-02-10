//devowel.c
//Leslie z5339245
// / June 2021

#include <stdio.h>

int is_vowel(int character);

int main(void) {

    int character = getchar();
    while (character != EOF) {

        is_vowel(character);

        character = getchar();
    }
    return 0;
}

int is_vowel(int character) {
    if (character != 'a' && character != 'e' &&
        character != 'i' && character != 'o' &&
        character != 'u') {
        printf("%c", character);
        return 0;
    } else {
        return 1;
    }
}









