//count_bigger.c
//z5339245 Leslie
#include <stdio.h>

// return the number of "bigger" values in an array (i.e. larger than 99
// or smaller than -99).
int count_bigger(int length, int array[]) {
    int x = 0;
    int number = 0;
    while (x < length) {
        if (array[x] > 99 || array[x] < -99) {
            number += 1;
        }
        x++;
    }
    // PUT YOUR CODE HERE (you must change the next line!)
    return number;
}

// This is a simple main function which could be used
// to test your count_bigger function.
// It will not be marked.
// Only your count_bigger function will be marked.

#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {141, 5, 92, 6, 535, -89, -752, -3};

    int result = count_bigger(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}
