//z5339245 Leslie Wu

#include <stdio.h>

int main() {
   char one;
   char two;
   char three;
   printf("Please enter three characters: ");
   scanf("%c %c %c",&one,&two,&three);
   if(one < two && two < three){
       printf("up\n");
   } else if(three < two && two < one){
       printf("down\n");
   } else{
       printf("neither\n");
   }
    return 0;
}
