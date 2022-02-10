//z5339245 Leslie Wu

#include <stdio.h>

int main() {
    int i;
    int j;
    int result;
    scanf("%d %d", &i, &j);
    result = i * j;
    if (result < 0) {
        result *= -1;
        printf("%d\n", result);
    } else if (result == 0) {
        printf("zero\n");
    } else {
        printf("%d\n", result);
    }
    return 0;
}
