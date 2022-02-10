//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the exercise - ask in the course forum.
//
// Week 8 Test Exercise: Deck Information
// main.c
//
// You must not change this file.
//
// THIS FILE WILL NOT BE MARKED
//
// A main function which calls the functions in `deck.h`.
//

#include <stdio.h>
#include <string.h>
#include <regex.h>

#include "deck.h"

int main(void) {
    struct deck *deck = create_deck();

    char card[MAX_CARD_LENGTH];
    printf("Enter cards:\n");
    while (fgets(card, MAX_CARD_LENGTH, stdin) != NULL) {
        int len = strlen(card);
        // Trim new line if added
        if (card[len - 1] == '\n') {
            card[len - 1] = '\0';
        }
        // Card can technically be a newline only, ignore this case.
        if (len != 1) {
            add_card(deck, card);
        }
    }

    printf("\nThis deck contains:\n");
    print_deck(deck);

    printf("\nThere are %d Hearts cards\n", count_suit(deck, 'H'));
    printf("There are %d Diamonds cards\n", count_suit(deck, 'D'));
    printf("There are %d Spades cards\n", count_suit(deck, 'S'));
    printf("There are %d Clubs cards\n", count_suit(deck, 'C'));

    return 0;
}
