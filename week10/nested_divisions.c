#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

struct pivot_data {
    int start;
    int end;
    int pivot;
};

double solve_division(char string[MAX_SIZE], int start, int end);
struct pivot_data get_pivot(char string[MAX_SIZE], int start, int end);
int find_pivot_point(char string[MAX_SIZE], int start, int end);

int main(void) {
    char input[MAX_SIZE];
    printf("Please enter a division expression: ");
    while (fgets(input, MAX_SIZE, stdin) != NULL) {
        printf("%lf\n", solve_division(input, 0, strlen(input) - 2));
        printf("Please enter a division expression: ");
    }
    return 0;
}

// Solves the division equation in the given string from the given range.
// Returns the result of this division.
double solve_division(char string[MAX_SIZE], int start, int end) {
    // Base case - String is exclusively a number
    int i = start;
    int is_number = 1;
    char intString[MAX_SIZE];
    while (i <= end) {
        intString[i - start] = string[i];
        if (!isdigit(string[i])) {
            is_number = 0;
            i = end;
        }
        i++;
    }
    intString[i - start] = '\0';
    if (is_number) {
        return atoi(intString);
    }

    // General case, where a division sign is involved
    struct pivot_data pivot = get_pivot(string, start, end);
    double dividend = solve_division(string, pivot.start, pivot.pivot - 1);
    double divisor = solve_division(string, pivot.pivot + 1, pivot.end);

    return dividend / divisor;
}

// Gets the final pivot point for the given string in the given range.
// Returns a struct with new start/end to handle redundant brackets.
struct pivot_data get_pivot(char string[MAX_SIZE], int start, int end) {
    int pivot_point = find_pivot_point(string, start, end);

    struct pivot_data res;
    res.start = start;
    res.end = end;
    res.pivot = pivot_point;
    /* Need to handle redundant brackets to actually find the pivot point.
     * E.g. ((8/4)/3) -> (8/4)/3
     * Since there could be multiple redundancies, a recursive call is
     * made to remove them.
     * E.g. (((((((((((90/2))))))))))) -> 90/2
     */
    if (pivot_point == start) {
        start++;
        end--;
        // res will be overwritten in this case
        res = get_pivot(string, start, end);
    }
    return res;
}

/* Attempts to find the pivot point in the given string, that
 * is, it will find the division sign that separates the largest
 * 2 expressions. E.g.
 *
 *                          80/2
 *                            ^
 *
 *                     (100/4)/(8/(4/2))
 *                            ^
 *
 * Returns the index in the given string to this point. If the point
 * isn't found, 'start' will be returned.
 */
int find_pivot_point(char string[MAX_SIZE], int start, int end) {
    int i = start;
    int pivot_point = i;
    int bracketCount = 0;
    while (i <= end && string[i] != '\0') {
        // Increment/decrement bracketCount to signal
        // whether opening brackets are waiting on closing ones
        if (string[i] == '(') {
            bracketCount++;
        } else if (string[i] == ')') {
            bracketCount--;
        }

        // Pivot found when no opening brackets are waiting
        // on closing brackets & '/' is seen
        if (bracketCount == 0 && string[i] == '/') {
            pivot_point = i;
            i = end;
        }
        i++;
    }

    return pivot_point;
}