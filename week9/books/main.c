//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the exercise - ask in the course forum.
//
// Week 8 Lab Exercise: Books
// main.c
//
// You must not change this file.
//
// THIS FILE WILL NOT BE MARKED
//
// Creates a linked list of books using a user's line by line input.
//

#include <stdio.h>

#include "books.h"

#define MAX_LINE_LENGTH 512

int main(void) {

    printf("Enter command: ");
    struct book *head = NULL;
    char line[MAX_LINE_LENGTH];
    int end_loop = 0;
    while (end_loop == 0 && fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        if (line[0] == 'i') {
            char command;
            char title[MAX_STR_LENGTH];
            char author[MAX_STR_LENGTH];
            int num_pages;
            sscanf(line, "%c %s %s %d", &command, title, author, &num_pages);

            head = insert_book(head, title, author, num_pages);

            printf("Enter command: ");
        } else if (line[0] == 'p') {
            print_books(head);

            printf("Enter command: ");
        } else if (line[0] == 'q') {
            end_loop = 1;
        }
    }

    return 0;
}