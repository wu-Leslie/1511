//secret_code.c
//Leslie z5339245

#include <stdio.h>


int main(void) {
    int array[100] = {0};
    int first_char;
    int second_char;
    int j = 0;
    int i = 0;
    int character = getchar();
    while (character != EOF) {
        array[i] = character;
        i++;
        character = getchar();
    }

    while (j < i) {
        first_char = array[j];
        j++;
        if (first_char == '\0') {
            break;
        }
        second_char = array[j];
        if (second_char == '\0') {
            break;
        }
        j++;
        if (first_char < second_char) {
            printf("%c", first_char);
        } else if (first_char >= second_char) {
            printf("%c", second_char);
        }
    }
    printf("\n");

    return 0;
}