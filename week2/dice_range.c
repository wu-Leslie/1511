#include <stdio.h>
// z5339245 Leslie Wu
int main(void){
    int sides;
    int dice;
    int value;
    double average = 0.0;
    printf("Enter the number of sides on your dice: ");
    scanf("%d" , &sides);
    printf("Enter the number of dice being rolled: ");
    scanf("%d",&dice);
    if(sides < 1 || dice < 1){
    printf("These dice will not produce a range.\n");}
    
    else {value = sides * dice;
    average = (dice + value)/2.0;
    printf("Your dice range is %d to %d.\n", dice ,value);
    printf("The average value is %lf\n",average);}
    return 0; 
    }
