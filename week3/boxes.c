//boxes.c
//z5339245 Leslie Wu
#include <stdio.h>

int main(void) {
    int number;
    printf("How many boxes: ");
    scanf("%d", &number);
    for (int height = 0; height < 4 * number - 1; ++height) {
        for (int i = 0; i < 4 * number - 1; ++i) {
            if (height < 2 * number) {
                if (i <= 2 * number - 1) {
                    if ((i <= height && i % 2 == 0) || (height <= i && height % 2 == 0)) {
                        printf("*");
                    } else {
                        printf("-");
                    }
                } else {
                    if (((4 * number - i - 2) <= height && i % 2 == 0) ||
                        (height <= (4 * number - i - 2) && height % 2 == 0)) {
                        printf("*");
                    } else {
                        printf("-");
                    }
                }
            } else {
                if (i <= 2 * number - 1) {
                    if ((i <= (4 * number - height - 2) && i % 2 == 0) ||
                        ((4 * number - height - 2) <= i && height % 2 == 0)) {
                        printf("*");
                    } else {
                        printf("-");
                    }
                } else {
                    if (((4 * number - i - 2) <= (4 * number - height - 2) && i % 2 == 0) ||
                    ((4 * number - height - 2) <= (4 * number - i - 2) && height % 2 == 0)) {
                        printf("*");
                    } else {
                        printf("-");
                    }

                }

            }
        }
        printf("\n");
    }


    return 0;

}
