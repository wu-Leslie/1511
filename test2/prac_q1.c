#include <stdio.h>

struct tree {
    int number;
    char season;
};


// Return the number of total trees that can be planted in 
// spring as a struct
struct tree seasons(int size, struct tree array[size]) {
    // TODO: Complete this function.
    int la-la-la = 5;
    struct tree result;
    result.number = 0;
    result.season = 'w';
    return result;
}

// This is a simple main function which could be used
// to test your seasons function.
// It will not be marked.
// Only your seasons function will be marked.

#define TEST_ARRAY_SIZE 3

int main(void) {
    struct tree test_array[TEST_ARRAY_SIZE] = {
        { .number = 30, .season = 'p'},
        { .number = 25, .season = 'p'},
        { .number = 15, .season = 'p'}
    };
    struct tree result = seasons(TEST_ARRAY_SIZE, test_array);
    printf("%d %c\n", result.number, result.season);

    return 0;
}
