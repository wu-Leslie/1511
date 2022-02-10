//frequency_analysis.c
//Leslie z5339245

#include <stdio.h>

#define ARRAY_SIZE 26

int letter_dispose(int character);

int main(void) {
    int letter_count[ARRAY_SIZE] = {0};
    int character = getchar();
    int letter_position = 0;
    double total_letter = 0;
    int i = 0;

    while (character != EOF) {
        if ((character >= 'a' && character <= 'z') ||
            (character >= 'A' && character <= 'Z')) {
            letter_position = letter_dispose(character);
            letter_count[letter_position] += 1;
            total_letter += 1;
        }
        character = getchar();
    }

    while (i < ARRAY_SIZE) {
        printf("'%c' %lf %d\n", 97 + i,
               letter_count[i] / total_letter, letter_count[i]);
        i++;
    }


    return 0;
}

int letter_dispose(int character) {
    if (character >= 'a' && character <= 'z') {
        return  character - 97;

    } else if (character >= 'A' && character <= 'Z') {
        return  character - 65;

    } else {
        return character;
    }

}












