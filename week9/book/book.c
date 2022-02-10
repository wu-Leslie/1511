//
// Author: INSERT-NAME-HERE (INSERT-ZID-HERE)
// Date: INSERT-DATE-HERE
//
// Description:
// INSERT-DESCRIPTION-HERE
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "books.h"

struct book {
    char title[30];
    char author[30];
    int num_pages;
    struct book *next;
    struct book *head;
    // TODO: You are required to fill in the fields of the struct.
    // You will need a next pointer and character arrays to store the title
    // and author.
};

struct book *insert_book(struct book *head, char *title, char *author, int num_pages) {
    // TODO: complete the function.
    struct book *new = malloc(sizeof(struct book));
    if (head == NULL) {

        strcpy(new->author, author);
        strcpy(new->title, title);
        new->num_pages = num_pages;
        new->next = NULL;
        head = new;
    }
    new = head;

    while (new->next != NULL) {
        new = new->next;
    }
    struct book *new2 = malloc(sizeof(struct book));
    strcpy(new2->author, author);
    strcpy(new2->title, title);
    new2->num_pages = num_pages;
    new2->next = NULL;

    new->next = new2;
    return head;
}

void print_books(struct book *head) {
    struct book *new = head;

    while (new->next != NULL){
        printf("%s by %s (%d pages)",new->title,new->author,new->num_pages);
        new = new->next;
    }
    // TODO: complete the function.

    return;
}