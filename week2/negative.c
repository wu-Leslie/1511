#include <stdio.h>

int main(void){
    int i;
    
    scanf("%d",&i);
    if(i>0){
    printf("You have entered a positive number.\n");}
    else if(i == 0){
    printf("You have entered zero.\n");}
    else{
    printf("Don't be so negative!\n");}
    
    return 0;
    }
