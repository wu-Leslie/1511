// CSE Valley
// cse_valley.c
//
// This program was written by Ethan(z5335411)
// on 2021.10.19
//
// Version 1.0.0 (2021-10-04): Assignment Released.
//
// TODO: Description of your program.

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 50
#define MAX_NUM_SEED_TYPES 26
#define LAND_SIZE 8
#define NO_SEED ' '
#define TRUE 1
#define FALSE 0

struct land {
    int is_watered;
    char seed_name;
};

struct seeds {
    char name;
    int amount;
};

struct farmer {
    int curr_col;
    int curr_row;
    char curr_dir;
};


// HINT: You will be using this function in stage 2!
void print_land(struct land farm_land[LAND_SIZE][LAND_SIZE], struct farmer cse_farmer);

// Provided functions use for game setup
// You do not need to use these functions yourself.
struct farmer initialise_farmer(struct farmer cse_farmer);
void initialise_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES]);
void initialise_land(struct land farm_land[LAND_SIZE][LAND_SIZE]);
void print_top_row(struct land farm_land[LAND_SIZE][LAND_SIZE], int row);
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE],
        struct farmer cse_farmer);
void seed_name_num(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int num);
void seed_command_all(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int num);
void seed_command_one(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int num);
struct farmer farmer_changed(struct farmer cse_farmer, char enter);
void farmer_doing(struct farmer cse_farmer
        , struct seeds seed_collection[MAX_NUM_SEED_TYPES]
                , struct land farm_land[LAND_SIZE][LAND_SIZE], int num);
void farmer_scattering(struct farmer cse_farmer, struct seeds seed_collection[MAX_NUM_SEED_TYPES]
        , struct land farm_land[LAND_SIZE][LAND_SIZE], int num);
void farmer_watering(struct farmer cse_farmer, struct seeds seed_collection[MAX_NUM_SEED_TYPES]
        , struct land farm_land[LAND_SIZE][LAND_SIZE]);


int main(void) {
    int seed_num;
    char seed_enter;

    struct farmer cse_farmer = {};
    cse_farmer = initialise_farmer(cse_farmer);

    struct land farm_land[LAND_SIZE][LAND_SIZE];
    initialise_land(farm_land);

    struct seeds seed_collection[MAX_NUM_SEED_TYPES];
    initialise_seeds(seed_collection);

    printf("Welcome to CSE Valley, farmer!\n");
    printf("Congratulations, you have received 60 seeds.\n");
    printf("How many different seeds do you wish to have? ");
    scanf("%d", &seed_num);
    //stage 1.1
    seed_name_num(seed_collection, seed_num);

    printf("Game Started!\n");

    // TODO: When you start stage 1.2, you will need to replace the below
    // with a loop that reads and executes commands until EOF.
    // See: https://cs1511.web.cse.unsw.edu.au/short/21T3_a1_explain/
    // for more information!
    printf("Enter command: ");
    while (scanf(" %c", &seed_enter) == 1) {
        if (seed_enter == 'a') {
            //stage 1.2
            seed_command_all(seed_collection, seed_num);
        } else if (seed_enter == 's') {
            //stage 1.3
            seed_command_one(seed_collection, seed_num);
        } else if (seed_enter == 'l') {
            //stage 2.1
            print_land(farm_land, cse_farmer);
        } else if (seed_enter == '<' || seed_enter == '>'
        || seed_enter == '^' || seed_enter == 'v') {
            //stage 2.2
            cse_farmer = farmer_changed(cse_farmer, seed_enter);
        } else if (seed_enter == 'o') {
            //stage 2.3
            farmer_doing(cse_farmer, seed_collection, farm_land, seed_num);
        } else if (seed_enter == 'p') {
            //stage 2.4
            farmer_scattering(cse_farmer, seed_collection, farm_land, seed_num);
        } else if (seed_enter == 'w') {
            //stage 3.1
            farmer_watering(cse_farmer, seed_collection, farm_land);
        }


        printf("Enter command: ");
    }

    return 0;
}


////////////////////////////////
//     Provided Functions     //
////////////////////////////////

// Prints the structs land (including locating where the
// farmer is)
// You will need this function in Stage 2.
void print_land(struct land farm_land[LAND_SIZE][LAND_SIZE],
        struct farmer cse_farmer) {
    printf("|---|---|---|---|---|---|---|---|\n");
    int i = 0;
    while (i < LAND_SIZE) {
        print_top_row(farm_land, i);
        // only prints mid and bottom row when the farmer
        // is in that row
        if (i == cse_farmer.curr_row) {
            print_farmer_row(farm_land, cse_farmer);
        }
        printf("|---|---|---|---|---|---|---|---|\n");
        i++;
    }
}

// NOTE: You do not need to directly call any of the functions
// below this point. You are allowed to modify them, but you
// do not need to.

// Initialises struct farmer to its default state upon starting
// in which the farmer will be on the top left of the farm
// facing to the right (as noted by '>')
struct farmer initialise_farmer(struct farmer cse_farmer) {
    cse_farmer.curr_col = 0;
    cse_farmer.curr_row = 0;
    cse_farmer.curr_dir = '>';
    return cse_farmer;
}

// Initialises a 2d array of struct land to its default state
// upon starting, which is that all land is unwatered and
// contains no seed
void initialise_land(struct land farm_land[LAND_SIZE][LAND_SIZE]) {
    int i = 0;
    while (i < LAND_SIZE) {
        int j = 0;
        while (j < LAND_SIZE) {
            farm_land[i][j].is_watered = FALSE;
            farm_land[i][j].seed_name = NO_SEED;
            j++;
        }
        i++;
    }
}

// Initialises struct farmer to its default state upon starting,
// which that all names are initialised as NO_SEED and its
// amount is 0
void initialise_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES]) {
    int i = 0;
    while (i < MAX_NUM_SEED_TYPES) {
        seed_collection[i].amount = 0;
        seed_collection[i].name = NO_SEED;
        i++;
    }
}

////////////////////////////////
//      Helper Functions      //
////////////////////////////////

// prints the top row of a particular struct land
void print_top_row(struct land farm_land[LAND_SIZE][LAND_SIZE], int row) {
    int j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        printf("%c", farm_land[row][j].seed_name);
        printf(" ");
        if (farm_land[row][j].is_watered == TRUE) {
            printf("W");
        } else {
            printf(" ");
        }
        j++;
    }
    printf("|");
    printf("\n");
}

// prints the 2 additional row when a farmer is in
// a particular row
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE],
        struct farmer cse_farmer)  {
    int j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        if (j == cse_farmer.curr_col) {
            if (cse_farmer.curr_dir == '<') {
                printf("<");
            } else {
                printf(" ");
            }
            if (cse_farmer.curr_dir == '^') {
                printf("^");
            } else {
                printf("f");
            }
            if (cse_farmer.curr_dir == '>') {
                printf(">");
            } else {
                printf(" ");
            }
        } else {
            printf("   ");
        }
        j++;
    }
    printf("|");
    printf("\n");
    j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        if (j == cse_farmer.curr_col) {
            printf(" ");
            if (cse_farmer.curr_dir == 'v') {
                printf("v");
            } else if (cse_farmer.curr_dir == '^') {
                printf("f");
            } else {
                printf(" ");
            }
            printf(" ");
        } else {
            printf("   ");
        }
        j++;
    }
    printf("|");
    printf("\n");
}

//stage 1.1.1
void seed_name_num(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int num) {
    int i = 0;
    printf("Enter the names of the seeds to be given:\n");
    while (i < num) {
        scanf(" %c", &seed_collection[i].name);
        seed_collection[i].amount = 60 / num;
        i++;
    }
}

//stage 1.2
void seed_command_all(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int num) {
    int i = 0;
    printf("  Seeds at your disposal:\n");
    while (i < num) {
        printf("  - %d seed(s) with the name '%c'\n", seed_collection[i].amount
               , seed_collection[i].name);
        i++;
    }
}

//stage 1.3
void seed_command_one(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int num) {
    char command_enter;
    int i = 0;
    scanf(" %c", &command_enter);
    if (command_enter < 'a' || command_enter > 'z') {
        printf("  Seed name has to be a lowercase letter\n");
    } else {
        while (i < num) {
            if (command_enter == seed_collection[i].name) {
                printf("  There are %d seeds with the name '%c'\n"
                       , seed_collection[i].amount, seed_collection[i].name);
                break;
            } i++;
            if (i == num) {
                printf("  There is no seed with the name '%c'\n", command_enter);
            }
        }
    }
}

//stage 2.2
struct farmer farmer_changed(struct farmer cse_farmer, char enter) {
    if (enter == cse_farmer.curr_dir) {
        if (enter == '>') {
            cse_farmer.curr_col += 1;
        } else if (enter == '<') {
            cse_farmer.curr_col -= 1;
        } else if (enter == 'v') {
            cse_farmer.curr_row += 1;
        } else if (enter == '^') {
            cse_farmer.curr_row -= 1;
        } cse_farmer.curr_dir = enter;
    } else {
        cse_farmer.curr_dir = enter;
    }
    if (cse_farmer.curr_col < 0) {
        cse_farmer.curr_col = 0;
    } else if (cse_farmer.curr_col > 7) {
        cse_farmer.curr_col = 7;
    } else if (cse_farmer.curr_row < 0) {
        cse_farmer.curr_row = 0;
    } else if (cse_farmer.curr_row > 7) {
        cse_farmer.curr_row = 7;
    }
    return cse_farmer;
}

//stage 2.3
void farmer_doing(struct farmer cse_farmer
        , struct seeds seed_collection[MAX_NUM_SEED_TYPES]
                , struct land farm_land[LAND_SIZE][LAND_SIZE], int num) {
    int i = 0;
    char command;
    char name;
    scanf(" %c", &command);
    if (command == 'w') {
        if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col < 7) {
            farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1].is_watered = TRUE;
        } else if (cse_farmer.curr_dir == '<' && cse_farmer.curr_col > 0) {
            farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1].is_watered = TRUE;
        } else if (cse_farmer.curr_dir == '^' && cse_farmer.curr_row > 0) {
            farm_land[cse_farmer.curr_row - 1][cse_farmer.curr_col].is_watered = TRUE;
        } else if (cse_farmer.curr_dir == 'v' && cse_farmer.curr_row < 7) {
            farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col].is_watered = TRUE;
        }
    } else if (command == 'p') {
        scanf(" %c", &name);
        if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col < 7) {
            farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1].seed_name = name;
        } else if (cse_farmer.curr_dir == '<' && cse_farmer.curr_col > 0) {
            farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1].seed_name = name;
        } else if (cse_farmer.curr_dir == '^' && cse_farmer.curr_row > 0) {
            farm_land[cse_farmer.curr_row - 1][cse_farmer.curr_col].seed_name = name;
        } else if (cse_farmer.curr_dir == 'v' && cse_farmer.curr_row < 7) {
            farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col].seed_name = name;
        } while (i < num) {
            if (name == seed_collection[i].name) {
                seed_collection[i].amount -= 1;
            } i++;
        }
    }
}

//stage 2.4
void farmer_scattering(struct farmer cse_farmer
        , struct seeds seed_collection[MAX_NUM_SEED_TYPES]
                , struct land farm_land[LAND_SIZE][LAND_SIZE], int num) {
    char name;
    int i = 0;
    int x = 0;
    int stop_num = 0;
    scanf(" %c", &name);
    if (name < 'a' || name > 'z') {
        printf("  Seed name has to be a lowercase letter\n");
        stop_num = 0;
    } else {
        while (i < num) {
            if (name == seed_collection[i].name) {
                stop_num = 1;
                break;
            } i++;
            if (i == num) {
                printf("  There is no seed with the name '%c'\n", name);
                stop_num = 0;
            }
        }
    }
    if (stop_num == 1) {
        if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col < 7) {
            while (cse_farmer.curr_col + x < 8 && seed_collection[i].amount > 0) {
                farm_land[cse_farmer.curr_row][cse_farmer.curr_col + x].seed_name = name;
                seed_collection[i].amount -= 1;
                x++;
            }
        } x = 0;
        if (cse_farmer.curr_dir == 'v' && cse_farmer.curr_row < 7) {
            while (cse_farmer.curr_row + x < 8 && seed_collection[i].amount > 0) {
                farm_land[cse_farmer.curr_row + x][cse_farmer.curr_col].seed_name = name;
                seed_collection[i].amount -= 1;
                x++;
            }
        }
        if (cse_farmer.curr_dir == '^' || cse_farmer.curr_dir == '<') {
            printf("  You cannot scatter seeds ^ or <\n");
        }
    }
}

//stage 3.1
void farmer_watering(struct farmer cse_farmer, struct seeds seed_collection[MAX_NUM_SEED_TYPES]
        , struct land farm_land[LAND_SIZE][LAND_SIZE]) {
    int size = 0;
    int i = 0;
    int x = 0;
    int row = cse_farmer.curr_row;
    int col = cse_farmer.curr_col;
    scanf(" %d", &size);
    i = cse_farmer.curr_row - size;
    if (size < 0) {
        printf("  The size argument needs to be a non-negative integer");
    } else {
        while (i <= row + size && i >= row - size) {
            x  = cse_farmer.curr_row - size;
            while (x <= col + size && x >= col - size) {
                if (i >= 0 && i <= 7 && x >= 0 && x <= 7) {
                    farm_land[i][x].is_watered = TRUE;
                } x++;
            } i++;
        }
    }
}