#include <stdio.h>

#include "library.h"

#define MAX_INPUT_LENGTH 1024

static int handle_command(struct library *library, char *input) {
    char command;
    if (input[0] == 'g') {
        char genre_name[MAX_STR_LENGTH];
        int res = sscanf(input, "%c %s", &command, genre_name);

        if (res != 2) {
            printf("Invalid command, use g <genre-name>\n");
        } else {
            add_genre(library, genre_name);
            printf("Added %s to genres!\n", genre_name);
        }
    } else if (input[0] == 'b') {
        char genre_name[MAX_STR_LENGTH];
        char title[MAX_STR_LENGTH];
        char author[MAX_STR_LENGTH];
        int n_pages;

        int res = sscanf(
                input, "%c %s %s %s %d", &command, genre_name, title, author,
                &n_pages
                );

        if (res != 5) {
            printf(
                    ""
                    "Invalid command, use "
                    "'b <genre-name> <book-name> <author> <#pages>'\n");
        } else {
            int status = add_book_to_genre(
                    library, genre_name, title, author, n_pages
                    );

            if (status == SUCCESS) {
                printf("Added %s to genre %s!\n", title, genre_name);
            } else {
                printf("Genre %s not found!\n", genre_name);
            }
        }
    } else if (input[0] == 'p') {
        char genre_name[MAX_STR_LENGTH];
        int res = sscanf(input, "%c %s", &command, genre_name);

        if (res != 2) {
            printf("Invalid command, use p <genre-name>\n");
        } else {
            print_books_in_genre(library, genre_name);
        }
    } else if (input[0] == 'q') {
        printf("Exiting\n");
        return 1;
    } else {
        printf("Unknown command was input.\n");
    }

    return 0;
}

int main(void) {
    char input[MAX_INPUT_LENGTH];

    struct library *library = create_library();

    printf("\nWelcome to the COMP1511 Library!\n\n");
    printf("Commands:\n");
    printf("- g <genre-name> ~ Add a Book Genre\n");
    printf("- b <genre-name> <book-name> <author> <#pages> ~ Add a Book\n");
    printf("- p <genre-name> ~ Print all Books in a Genre\n\n");

    int exit = 0;

    printf("--> ");
    while (!exit && fgets(input, MAX_INPUT_LENGTH, stdin) != NULL) {
        exit = handle_command(library, input);
        if (!exit) {
            printf("--> ");
        }
    }
}