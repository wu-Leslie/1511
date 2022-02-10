//common_elements.c
//z5339245 Leslie Wu
// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination
#include <stdio.h>

int main(void ){


    return 0;
}

int common_elements(int length, int source1[length],
                    int source2[length], int destination[length]) {

    int x;
    int y = 0;
    int destination_num = 0;
    while (y < length) {
        x = 0;
        while (x < length) {
            if (source1[y] == source2[x]) {
                destination[destination_num] = source1[y];
                destination_num++;
                break;
            }
            x++;
        }
        y++;
    }
    // PUT YOUR CODE HERE (you must change the next line!)
    return destination_num;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.