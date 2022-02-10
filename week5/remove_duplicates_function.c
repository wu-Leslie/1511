//remove_duplicates_function.c
//By Leslie z5339245

#include <stdio.h>

int remove_duplicates(int length, int source[length], int destination[length]);


int main(void) {

    return 0;
}

int remove_duplicates(int length, int source[length], int destination[length]) {
    int x = 0;
    int y;
    int destination_length = 0;
    int state;
    while (x < length) {
        y = 0;
        state = 1;
        while (y < destination_length) {
            if (source[x] == destination[y]) {
                state = 0;
            }
            y++;
        }

        if (state == 1) {
            destination[destination_length] = source[x];
            destination_length++;
        }
        x++;
    }
    return destination_length;
}
