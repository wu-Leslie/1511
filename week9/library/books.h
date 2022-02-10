//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the exercise - ask in the course forum.
//
// Week 8 Lab Exercise: Books
// books.h
//
// You must not change this file.
//
// THIS FILE WILL NOT BE MARKED
//
// Details the functions required.
//

#ifndef _BOOKS_H_
#define _BOOKS_H_

#define MAX_STR_LENGTH 128

// This struct represents the information on a book.
//
// Note that other files outside of the implementation file cannot see the
// contents of the struct.
struct book;

// Creates a new book and inserts the book at the end of the linked list.
//
// `insert_book` will be passed in the parameters:
// - `head` -- the head of a linked list of struct books. If `head` is NULL,
//   this means the linked list is empty.
// - `title` -- the title of the book to insert.
// - `author` -- the name of the author of the book to insert.
// - `num_pages` -- the number of pages in the book to insert.
//
// `insert_book` will return the head of the linked list.
//
// ASSUMPTIONS:
// - `title` and `author` will never be longer than MAX_STR_LENGTH.
// - `num_pages` will always be greater than or equal to 1.
struct book *insert_book(struct book *head, char *title, char *author, int num_pages);

// Prints a linked list of books.
//
// Each book should be printed in the format:
// "{title} by {author} ({num_pages} pages)\n"
//
// If the linked list is empty, print nothing.
//
// `print_books` will be passed in the parameters:
// - `head` -- the head of a linked list of struct books. If `head` is NULL,
//   this means the linked list is empty.
//
// `print_books` will return nothing.
void print_books(struct book *head);

#endif // _BOOKS_H_