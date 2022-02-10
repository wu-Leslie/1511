//perfect.c
//z5339245 Leslie Wu
#include <stdio.h>

int main(void) {
    int real_sum = 0;
    int number;
    int sum = 0;
    printf("Enter number: ");
    scanf("%d", &number);
    printf("The factors of %d are:\n",number);
    for (int i = 1; i < number; ++i) {
        if (number % i == 0){
            printf("%d\n",i);
            sum += i;
        }
    }
    printf("%d\n",number);
    real_sum = sum + number;
    printf("Sum of factors = %d\n",real_sum);

    if(sum == number){
        printf("%d is a perfect number\n",number);
    } else{
        printf("%d is not a perfect number\n",number);
    }
    return 0;
}

