//loop_sum.c
// By Leslie z5339245


#include <stdio.h>

int main(void) {
    int sum = 0;
    int enter_number;
    int number;
    printf("How many numbers: ");
    scanf("%d", &number);
    int x = number;
    while (x>0){
        scanf("%d",&enter_number);
        sum += enter_number;
        x--;
    }
    printf("The sum is: %d\n",sum);
    return 0;
}