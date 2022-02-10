//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the exercise - ask in the course forum.
//
// Week 8 Lab Exercise: Fractions
// main.c
//
// You must not change this file.
//
// THIS FILE WILL NOT BE MARKED
//
// A main function which calls the functions in `fractions.h`.
//

#include <stdio.h>
#include <string.h>

#include "fractions.h"

void print_usage(void);

int main(int argc, char *argv[]) {

    if (argc <= 1) {
        print_usage();
        return 0;
    } else if (!strcmp(argv[1], "convert") && !strcmp(argv[1], "add")) {
        print_usage();
        return 0; 
    } else if (strcmp(argv[1], "convert") == 0 && argc != 3) {
        print_usage();
        return 0;
    } else if (strcmp(argv[1], "add") == 0 && argc != 4) {
        print_usage();
        return 0;
    }

    if (strcmp(argv[1], "convert") == 0) {
        struct fraction frac;
        sscanf(argv[2], "%d/%d", &(frac.top), &(frac.bottom));
        printf(
            "%d / %d converts to %lf\n",
            frac.top,
            frac.bottom,
            convert(frac)
        );
    } 

    if (strcmp(argv[1], "add") == 0) {
        struct fraction first;
        sscanf(argv[2], "%d/%d", &(first.top), &(first.bottom));
        struct fraction second;
        sscanf(argv[3], "%d/%d", &(second.top), &(second.bottom));
        
        struct fraction result = add(first, second);
        printf(
            "%d / %d + %d / %d = %d / %d\n",
            first.top,
            first.bottom,
            second.top,
            second.bottom,
            result.top,
            result.bottom
        );
    }

    return 0;
}

void print_usage(void) {
    printf("Usage: ./fractions convert <fraction> OR add <fraction> <fraction>\n");

    return;
}