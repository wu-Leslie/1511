//wondrous.c
//z5339245 Leslie Wu
#include <stdio.h>

int main(void) {
    int see_number;
    printf("What number would you like to see: \n");
    scanf("%d", &see_number);
    while (see_number != 2) {
        for (int i = 0; i < see_number; ++i) {
            printf("*");
        }
        if (see_number % 2 == 0) {
            see_number = see_number / 2;
        } else {
            see_number = 3 * see_number + 1;
        }
        printf("\n");
        if(see_number==2){
            printf("**\n");
        }
    }
    return 0;
}

