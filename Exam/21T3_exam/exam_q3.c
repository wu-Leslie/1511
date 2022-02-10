#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number;
    int array[100] = {0};
    int length = 0;
    int x = 0;
    while (scanf("%d", &number) == 1 && number != 0) {
        array[length] = number;
        length++;
        number = getchar();
    }
    if (length % 2 == 1) {
        length = length / 2 + 1;
    } else {
        length /= 2;
    }
    printf("First Half: ");
    while (x < length) {
        printf("%d ", array[x]);
        x++;
    }
    printf("\n");
}
