//hourglass.c
// By Leslie z5339245


#include <stdio.h>

int main(void) {
    int size;

    printf("Please enter a size: ");
    scanf("%d", &size);
    int length = 0;
    int height = 0;
    while (height <= size - 1) {
        length = 0;
        while (length <= size - 1) {
            if (height < size / 2) {
                if (length >= height && length <= size - height - 1) {
                    printf("*");
                } else {
                    printf("-");
                }
            } else {
                if (length >= size - height - 1 && length <= height) {
                    printf("*");
                } else {
                    printf("-");
                }
            }
            length++;

        }
        printf("\n");
        height++;
    }

}