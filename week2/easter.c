// z5339245 Leslie Wu
#include <stdio.h>


int main(void) {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    int Easter_Month = (h + l - 7 * m + 114) / 31;  //[3=March, 4=April]
    int p = (h + l - 7 * m + 114) % 31;
    int Easter_Date = p + 1;//(date in Easter Month)
    if (Easter_Month == 3) {
        printf("Easter is March %d in %d.\n", Easter_Date, year);
    }
    if (Easter_Month == 4) {
        printf("Easter is April %d in %d.\n", Easter_Date, year);
    }
    return 0;
}

