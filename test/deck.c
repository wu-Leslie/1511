// Small library to handle various operations on a deck of cards.
// Written by YOUR-NAME-HERE (YOUR-ZID) on DATE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "deck.h"


// Creates a new deck, this has already been done for you.
struct deck *create_deck() {
    struct deck *new = malloc(sizeof(struct deck));
    new->n_cards = 0;

    return new;
}

void add_card(struct deck *deck, char *card) {
    strcpy(deck->cards[deck->n_cards], card);
    deck->n_cards += 1;

    // TODO: Complete this function
    return;
}

void print_deck(struct deck *deck) {
    int i = 0;
    while (i < deck->n_cards) {
        printf("%s\n", deck->cards[i]);
        i++;
    }
    // TODO: Complete this function
    return;
}

int count_suit(struct deck *deck, char suit) {
    int i = 0;
    int j;
    int number = 0;
    while (i < deck->n_cards) {
        j = 0;
        while (deck->cards[i][j] != '\0') {
            if (deck->cards[i][j] == suit) {
                number += 1;
            }
            j++;
        }
        i++;
    }
    // TODO: Complete this function
    return number;
}