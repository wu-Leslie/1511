// If you're looking for the part1_q .c files, we are only
// providing them in the exam paper. There is no way to
// download them, but you can copy them yourself if you would like!
//
// You cannot submit this file; please ignore it.

#include<stdio.h>

int main() {
    struct drink {
        int fizziness;
        char first_letter;
    };

    void print_drink_type(struct drink my_drink) {
        if (my_drink.fizziness > 0) {
            if (my_drink.first_letter == 'p') {
                printf("Pepsi");
            } else {
                printf("Coca Cola");
            }
        } else if (my_drink.fizziness == 0) {
            printf("Water");
        }
    }
    return 0;
}