//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the exercise - ask in the course forum.
//
// Week 8 Lab Exercise: Library
// library.h
//
// You must not change this file.
//
// THIS FILE WILL NOT BE MARKED
//
// Details the functions required.
//

#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include "books.h"

#define SUCCESS 0
#define NOT_FOUND 1

//
// `struct genre` represents all a single genre specified by name.
//  It contains a linked list of books and a pointer to the next
//  genre.
//
struct genre {
    char name[MAX_STR_LENGTH];

    struct book *books;
    struct genre *next;
};

//
// `struct library` represents an entire physical library containing genres
// and books.
//
// `genres` is the head of a linked list of `struct genre`s which will contain
// a linked list of books.
//
struct library {
    struct genre *genres;
};

//
// Creates a new `struct library` and returns a pointer to it.
//
// `create_library` takes in no parameters.
//
// `create_library` will return a pointer to a new `struct library`.
//
struct library *create_library();

//
// Adds a genre to the head of the provided library of `genre`
//
// `add_genre` takes in these parameters:
// - `lib` a pointer to the `struct library` to add the genre to
// - `genre` name of the genre to add to the library
//
// `add_genre` returns nothing.
//
// ASSUMPTIONS:
// - `lib` will always be a valid pointer
// - `genre_name` will always be a valid string of `MAX_STR_LENGTH` size
//
void add_genre(struct library *lib, char *genre);

//
// Adds a book to the end of the desired genre in the desired library.
//
// `add_book_to_genre` takes in these parameters:
// - `lib` - a pointer to the `struct library` to add the book to
// - `genre` - name of the desired genre for the book to add to the library
// - `title` - name of the book to add to the genre
// - `author` - The author of the book
// - `n_pages` - Number of pages in the book
//
// `add_book_to_genre` returns, in order of precedence:
// `NOT_FOUND` if genre was not found in library
// `SUCCESS` if book is added
//
// ASSUMPTIONS:
// - `lib` will always be a valid pointer
// - `genre` will always be a valid string of `MAX_STR_LENGTH` size
// - `title` will always be a valid string of `MAX_STR_LENGTH` size
// - `author` will always be a valid string of `MAX_STR_LENGTH` size
// - `n_pages` will always be a positive integer
//
int add_book_to_genre(
        struct library *lib,
                char *genre,
                char *title,
                char *author,
                int n_pages
                );

//
// Prints all the books in the desired genre
//
// Each book of the genre is printed on a new line in the format specified
// in the function `print_books()` in "book.h"
// ...
//
// `print_books_in_genre` takes in these parameters:
// - `lib` a pointer to the `struct library` to print the genre
// - `genre` name of the genre in the library to print books from
//
// `print_books_in_genre` returns nothing.
//
// ASSUMPTIONS:
// - `lib` will always be a valid pointer
// - `genre` will always be a valid string of `MAX_STR_LENGTH` size

void print_books_in_genre(struct library *lib, char *genre);

#endif // _LIBRARY_H_