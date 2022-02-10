//./sawtooth
//z5339245
#include <stdio.h>

int main(void) {
    int height;
    int length;
    printf("Please enter the height of the sawtooth:");
    scanf("%d", &height);
    printf("Please enter the length of the sawtooth:");
    scanf("%d", &length);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= length; j++) {
            if (j == length) {
                printf("\n");
            } else if (j % height == 0 || j % height == i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
    }

    return 0;

}
