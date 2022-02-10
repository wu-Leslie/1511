//line_char.c
//Leslie z5339245
// / June 2021

#include <stdio.h>


int main(void) {
    int array[100] = {0};
    int i = 0;
    int j = 0;
    int number;
    int character = getchar();
    while (character != '\n') {
        array[i] = character;
        i++;

        character = getchar();
    }
    scanf(" %d",&number);
    while (j < i) {
        if (j == number) {
            printf("The character in position %d is '%c'\n",j,array[j]);
        }
        j++;
    }
    return 0;
}