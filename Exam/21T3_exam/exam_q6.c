#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LEN 100

struct arg_node {
    char data[MAX_LEN];
    struct arg_node *next;
};

static struct arg_node *strings_to_list(int len, char *strings[]);

int evaluate_reverse_polish_notation(struct arg_node *head);

void free_arg_list(struct arg_node *head);

int calculate(int number1, int number2, char symbol);

// your exam q6 code here!
int evaluate_reverse_polish_notation(struct arg_node *head) {
    struct arg_node *new = head;
    int position_char = 0;
    int result;
    int x = 0;
    int symbol_number = 0;
    while (new != NULL) {

        if (new->data[0] == '+' || new->data[0] == '-' || new->data[0] == 'x' || new->data[0] == '/') {
            break;
        }

        position_char++;
        new = new->next;

    }

    position_char = position_char - 2;
    new = head;
    while (position_char > x){
        new =  new->next;
        x++;
    }
    int number1 = atoi(new->data);
    new = new->next;
    int number2 = atoi(new->data);
    new = new->next;
    char symbol = new->data[position_char];
    result = calculate(number1, number2, symbol);

    new = head;

    while (new != NULL) {
        if (new->data[0] == '+' || new->data[0] == '-' || new->data[0] == 'x' || new->data[0] == '/') {
            symbol_number += 1;
        }
        new = new->next;
    }

    if (symbol_number > 1) {
        while (position_char > 0){
            new =  new->next;
            position_char--;
        }
        strcpy(new->data,itoa(result));
        struct arg_node *new1 = new;
        new1 = new1->next->next;
        new->next = new1->next;

//        while (i < position_char) {
//            array[i] = new->data[i];
//            i++;
//        }
//        array[i] = result;
//        i++;
//        position_char += 2;
//        while (position_char < MAX_LEN) {
//            array[i] = new->data[position_char];
//            i++;
//            position_char++;
//        }
//        new = new->next;
//        i = 0;
//        while (i < MAX_LEN) {
//            new->data[i] = array[i];
//            i++;
//        }
        result = evaluate_reverse_polish_notation(new);
    }


    return result;
}

int calculate(int number1, int number2, char symbol) {
    int result;
    if (symbol == '-') {
        result = number1 - number2;
    } else if (symbol == '+') {
        result = number1 + number2;
    } else if (symbol == 'x') {
        result = number1 * number2;
    } else {
        result = number1 / number2;
    }
    return result;
}

///////////// PROVIDED CODE ///////////////
// DO NOT MODIFY THESE FUNCTIONS

// we may use a different main function for marking
// please ensure your evaluate_reverse_polish_notation function is implemented. 
// DO NOT MODIFY THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    int length = argc - 1;
    struct arg_node *head = strings_to_list(length, &argv[1]);

    printf("%d\n", evaluate_reverse_polish_notation(head));
    free_arg_list(head);

    return 0;
}

// create linked list from array of strings
static struct arg_node *strings_to_list(int len, char *strings[]) {
    struct arg_node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct arg_node *n = malloc(sizeof(*n));
        assert(n != NULL);
        n->next = head;
        strcpy(n->data, strings[i]);
        head = n;
    }
    return head;
}

void free_arg_list(struct arg_node *head) {
    if (head == NULL) return;
    free_arg_list(head->next);
    free(head);
}

