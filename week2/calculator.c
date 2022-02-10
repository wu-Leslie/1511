#include <stdio.h>

int main(void){
    int first_number;
    int x;
    int y;
    printf("Enter instruction: ");
    scanf("%d %d %d",&first_number,&x,&y);
    if(first_number == 1){
        printf("%d\n", x+y); 
        }   
    if(first_number == 2){
        printf("%d\n", x-y); 
        }
        
    return 0;
    }
