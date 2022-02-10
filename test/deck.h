//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the exercise - ask in the course forum.
//
// Week 8 Lab Exercise: Deck Information
// deck.h
//
// You must not change this file.
//
// THIS FILE WILL NOT BE MARKED
//
// Details the functions required.
//

#ifndef _DECK_H_
#define _DECK_H_

#define MAX_DECK 52
#define MAX_CARD_LENGTH 4

#define N_VALUES 13
#define N_SUITS 4

// `struct deck` is how we hold the information of a deck.
//
// `cards` refers to the physical cards that are within the deck. It is an
// array of strings with a max of MAX_DECK cards.
//
// `n_cards` refers to the number of cards actually in the deck at a given time.
// This number is between (0, MAX_DECK - 1) inclusive.
//
struct deck {
    char cards[MAX_DECK][MAX_CARD_LENGTH];
    int n_cards;
};

// Creates a new deck and returns a pointer to it.
//
// `convert` will be passed no parameters.
//
// `convert` will return a pointer to this new deck.
//
// ASSUMPTIONS:
// - This function will always be successful
//
struct deck *create_deck();

// Adds a card to the given deck at the next available position.
//
// Every `card` you are given will be in the format of <value><suit> like below:
//
// 3C
// 10H
// KS
//
// Which correspond to "3 of clubs", "10 of hearts" and "King of spades"
// respectively.
//
// `add_card` will be passed in the parameters:
// - `deck` -- a pointer to a `struct deck`.
// - `card` -- a string representing a card, in the format "<value><suit>".
//
// `add_card` will return nothing.
//
// ASSUMPTIONS:
// - `deck` will always be a valid `struct deck`
// - `card` will always be a valid string of the defined format
//
void add_card(struct deck *deck, char *card);

// Prints all the cards out in a given deck. They are printed in the order they
// were added.
//
// All cards will be printed exactly how they were added. For example, if
// "5C" was added with `add_card`, then "5C" will be printed out.
//
// `print_deck` will be passed in the parameters:
// - `deck` -- a pointer to a `struct deck`.
//
// `print_deck` will return nothing.
//
// ASSUMPTIONS:
// - `deck` will always be a valid `struct deck`
//
void print_deck(struct deck *deck);

// Counts the number of cards that have a given suit in a given deck.
//
// For example, if the following cards in the deck:
// 5H, 3H, 2S, 9H, 5C, 10D
//
// And 'H' was the suit input, this function would return 3 as there are three
// cards of the hearts suit.
//
// `add_card` will be passed in the parameters:
// - `deck` -- a pointer to a `struct deck`.
// - `suit` -- a char representing a suit, will be 'H', 'D', 'S' or 'C'
//
// `count_suit` will return the number of cards in the deck that are of this
// suit.
//
// ASSUMPTIONS:
// - `deck` will always be a valid `struct deck`
// - `suit` will always be a valid suit
//
int count_suit(struct deck *deck, char suit);


#endif // _FRACTIONS_H_