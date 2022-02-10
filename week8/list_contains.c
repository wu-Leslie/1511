//z5339245 Leslie
//list_contains.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STRING_SIZE 1024

struct node {
    struct node *next;
    char data[MAX_STRING_SIZE];
};

int contains(char *value, struct node *head);

struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    char value[MAX_STRING_SIZE];
    fgets(value, MAX_STRING_SIZE, stdin);

    // Remove new line if added
    int len = strlen(value);
    if (value[len - 1] == '\n') {
        value[len - 1] = '\0';
    }

    // create linked list from command line arguments
    struct node *head = NULL;
    if (argc > 1) {
        // list has elements
        head = strings_to_list(argc - 1, &argv[1]);
    }

    int result = contains(value, head);
    printf("%d\n", result);

    return 0;
}


// Return 1 if value occurs in linked list, 0 otherwise
int contains(char *value, struct node *head) {
    int state = 0;
    while (head != NULL) {

        if (strcmp(value, head->data) == 0) {

            state = 1;
        }
        head = head->next;
    }

    // PUT YOUR CODE HERE (change the next line!)
    return state;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof(struct node));
        assert(n != NULL);
        n->next = head;
        strcpy(n->data, strings[i]);
        head = n;
        i -= 1;
    }
    return head;
}