// identity_matrix.c
//z5339245 Leslie
#include <stdio.h>
#include <stdlib.h>


void make_identity(int size, int matrix[size][size]);
void print_matrix(int size, int matrix[size][size]);

// This is a simple main function that you can use to test your identity_matrix
// function.
// It will not be marked - only your make_identity function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your make_identity function directly.
// Any changes that you make to this main function will
// not affect the autotests.
int main(void){

    int array3[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    make_identity(3, array3);

    print_matrix(3, array3);

    return 0;
}

//Makes a square matrix into an identity matrix
void make_identity(int size, int matrix[size][size]) {
    int x = 0;
    int y;
    while (x < size) {
        y = 0;
        while (y < size) {
            if(x == y){
                matrix[x][y] = 1;
            } else{
                matrix[x][y] = 0;
            }
            y++;
        }
        x++;

    }
    //TODO: Complete this function
}

//Prints out a square matrix of any size
void print_matrix(int size, int matrix[size][size]) {
    int i = 0;
    while (i < size){
        int j = 0;
        while (j < size){
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

}

