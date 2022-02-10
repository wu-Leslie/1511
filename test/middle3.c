//middle.c
// By Leslie z5339245
//

// Program to scan in three integers and print out the middle one.

#include <stdio.h>

struct numbers {
    int first;
    int second;
    int third;
};

int main(void) {
    // DO NOT CHANGE CODE BELOW HERE
    struct numbers nums;
    int result = 0;
    printf("Enter integer: ");
    scanf("%d", &nums.first);

    printf("Enter integer: ");
    scanf("%d", &nums.second);

    printf("Enter integer: ");
    scanf("%d", &nums.third);
    // DO NOT CHANGE CODE ABOVE HERE
    if ((nums.first <= nums.second && nums.second <= nums.third) ||
        (nums.third <= nums.second && nums.second <= nums.first)) {
        result = 2;
    }
    if ((nums.second <= nums.first && nums.first <= nums.third) || (nums.third <= nums.first && nums.first <= nums.second)) {
        result = 1;

    }
    if ((nums.first <= nums.third && nums.third <= nums.second) || (nums.second <= nums.third && nums.third <= nums.first)) {
        result = 3;
    }


    if(result == 1){
        printf("Middle: %d\n",nums.first);
    } else if(result == 2){
        printf("Middle: %d\n",nums.second);
    } else if(result == 3){
        printf("Middle: %d\n",nums.third);
    }
    // ADD CODE BELOW HERE
    // TODO: print out the middle integer of the three scanned in


    return 0;
}