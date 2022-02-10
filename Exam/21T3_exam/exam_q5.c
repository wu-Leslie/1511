#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(int argc, char *argv[]) {
    char input[100] = {0};
    char letter;
    int position_l = 0;
    int x = 0;
    int y = 1;
    int z;
    int state = 0;
    while (scanf("%c", &letter) == 1 && letter != '\n') {
        input[position_l] = letter;
        position_l++;
    }
    while (y < argc) {
        x = 0;
        state = 0;

        while (x < position_l) {
            z = 0;
            while (z < strlen(argv[y])) {
                if (argv[y][z] == input[z]) {
                    state = 1;
                    break;

                }
                z++;
            }
            if (state == 1) {
                printf("%d %s\n", z, argv[y]);
                break;
            }

            x++;
        }
        y++;
    }

    //TODO: Your solution should go here
    //You can use functions if you would like to
    return 0;
}

