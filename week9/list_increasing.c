//list_increasing.c
//z5339245 Leslie
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int data;
};

int increasing(struct node *head);

struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = increasing(head);
    printf("%d\n", result);

    return 0;
}


// return 1 if values in a linked list are in increasing order,
// return 0, otherwise

int increasing(struct node *head) {
    int compare_n = 0;
    if (head == NULL) {
        return 1;
    }
    while (head != NULL) {

        if (compare_n < head->data) {
            compare_n = head->data;
        } else {
            return 0;
        }
        head = head->next;
    }
    // PUT YOUR CODE HERE (change the next line!)
    return 1;

}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof(struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}