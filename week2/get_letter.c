#include <stdio.h>

int main(void) {
    char x;
    char letter;
    int y;
    printf("Uppercase:");
    scanf("%c", &x);
    if (x != 'n' && x != 'y') {
        printf("You need to enter 'y' or 'n'\n");
        printf("Exiting the program with error code 1\n");
        return 1;
    }
    
    printf("Index:");
    scanf("%d", &y);

    if (x == 'y' && y <= 26 && y >= 1) {
        letter = y + 'A' - 1;
        printf("The letter is %c\n", letter);
    } else if (x == 'n' && y <= 26 && y >= 1) {
        letter = y + 'a' - 1;
        printf("The letter is %c\n", letter);

    } else {
        printf("You need to enter a number between 1 and 26 inclusive\n");
        printf("Exiting the program with error code 2\n");
        return 2;
    }


}
