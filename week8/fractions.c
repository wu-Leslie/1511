//z5339245 Leslie
//fraction.c


#include "fractions.h"

// These are function stubs!
// They are functions which compile but do not have the correct behaviour.

double convert(struct fraction frac) {
    // TODO: complete the function
    int top = frac.top;
    double bottom = frac.bottom;
    double result = top / bottom;
    return result;
}

struct fraction add(struct fraction first, struct fraction second) {
    // TODO: complete the function
    int i = 2;
    int first_top = first.top;
    int first_bottom = first.bottom;
    int second_top = second.top;
    int second_bottom = second.bottom;
    struct fraction result;
    result.top = first_top * second_bottom + first_bottom * second_top;
    result.bottom = first_bottom * second_bottom;
    while (i < 9) {
        if (result.top % i == 0 && result.bottom % i == 0) {
            result.top /= i;
            result.bottom /= i;
        }
        i++;
    }

    return result;
}