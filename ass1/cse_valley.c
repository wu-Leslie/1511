//cse_valley.c
//z5339245 Leslie Wu
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

struct plant_num {
    int number;
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

void printing_all_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int types);

void scanning_in_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int types);

void printing_one_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int types);

struct farmer no_direction_change(struct farmer cse_farmer, char direction);

struct farmer direction_change(struct farmer cse_farmer, char direction);

void attending_adjacent_land(struct farmer cse_farmer, struct land farm[LAND_SIZE][LAND_SIZE],
                             struct seeds seed_collection[MAX_NUM_SEED_TYPES], int types);

void planting_multiple_seeds(struct farmer cse_farmer, struct land farm[LAND_SIZE][LAND_SIZE],
                             struct seeds seed_collection[MAX_NUM_SEED_TYPES], int types);

void square_watering(struct farmer cse_farmer, struct land farm[LAND_SIZE][LAND_SIZE]);

int new_day(struct land farm[LAND_SIZE][LAND_SIZE], struct farmer *cse_farmer, int day);

void harvesting_adjacent_land(struct land farm[LAND_SIZE][LAND_SIZE],
                              struct farmer cse_farmer, int seed_types,
                              struct seeds seed_collection[MAX_NUM_SEED_TYPES]);

int seeds_trading(struct seeds seed_collection[MAX_NUM_SEED_TYPES], int types);

void natural_disasters(struct land farm[LAND_SIZE][LAND_SIZE],
                       struct plant_num plant_number[LAND_SIZE][LAND_SIZE]);

void get_around_plants(struct land farm[LAND_SIZE][LAND_SIZE],
                       struct plant_num plant_number[LAND_SIZE][LAND_SIZE]);

int main(void) {
    int seed_types;
    char command;
    int day = 1;


    struct farmer cse_farmer = {};
    cse_farmer = initialise_farmer(cse_farmer);

    struct land farm_land[LAND_SIZE][LAND_SIZE];
    initialise_land(farm_land);

    struct seeds seed_collection[MAX_NUM_SEED_TYPES];
    initialise_seeds(seed_collection);

    struct plant_num plant_number[LAND_SIZE][LAND_SIZE];


    printf("Welcome to CSE Valley, farmer!\n");
    printf("Congratulations, you have received 60 seeds.\n");
    printf("How many different seeds do you wish to have? ");
    scanf("%d", &seed_types);

    printf("Enter the names of the seeds to be given: \n");
    scanning_in_seeds(seed_collection, seed_types);
    //step 1.1

    printf("Game Started!\n");
    // with a loop that reads and executes commands until EOF.
    // See: https://cs1511.web.cse.unsw.edu.au/short/21T3_a1_explain/
    // for more information!
    printf("Enter command: ");

    while ((scanf(" %c", &command)) == 1) {

        if (command == 'a') {
            printing_all_seeds(seed_collection, seed_types);
            //step 1.2
        } else if (command == 's') {
            //print only one seed 1.3
            printing_one_seeds(seed_collection, seed_types);
        } else if (command == 'l') {
            print_land(farm_land, cse_farmer);
            //print the farm 2.1.1
        } else if (command == '<' || command == '>' ||
                   command == 'v' || command == '^') {
            cse_farmer = direction_change(cse_farmer, command);
            // move direction 2.2.1
        } else if (command == 'o') {
            attending_adjacent_land(cse_farmer, farm_land,
                                    seed_collection, seed_types);
            //2.3: Attending to an Adjacent Land
        } else if (command == 'p') {
            planting_multiple_seeds(cse_farmer, farm_land,
                                    seed_collection, seed_types);
            //2.4: Scattering Seeds
        } else if (command == 'w') {
            square_watering(cse_farmer, farm_land);
            //3.1: Square Watering
        } else if (command == 'n') {
            day = new_day(farm_land, &cse_farmer, day);
            printf("  Advancing to the next day... Day %d, let's go!\n", day);
            //3.2: Advancing to the Next Day and Harvesting
        } else if (command == 'h') {
            harvesting_adjacent_land(farm_land, cse_farmer, seed_types, seed_collection);
            //3.2.1 harvesting seeds
        } else if (command == 't') {
            seed_types = seeds_trading(seed_collection, seed_types);
            //3.3: Trading Seeds
        } else if (command == 'd') {
            natural_disasters(farm_land, plant_number);
            //4.1: Natural Disasters - Droughts
            //4.2: Natural Disasters - Wind Storms
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

// prints the 2 additional row when a farmer is in.
// a particular row.
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE],
                      struct farmer cse_farmer) {
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

//use this function can print all seeds you need.
void printing_all_seeds(struct seeds seed_collection
[MAX_NUM_SEED_TYPES], int types) {
    int x = 0;
    printf("  Seeds at your disposal:\n");
    while (types > 0) {
        printf("  - %d seed(s) with the name '%c'\n",
               seed_collection[x].amount, seed_collection[x].name);
        types--;
        x++;
    }
}

//use this function can put the name and amount in the seeds array.
void scanning_in_seeds(struct seeds seed_collection
[MAX_NUM_SEED_TYPES], int types) {
    int x = 0;
    int y = types;
    char name;
    while (y > 0) {
        scanf(" %c", &name);
        seed_collection[x].name = name;
        seed_collection[x].amount = 60 / types;
        x++;
        y--;
    }
}

//use this function can print only one seed you want to see.
void printing_one_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES],
                        int types) {
    int y = types;
    int x = 0;
    int i = 0;
    char seed_name;
    scanf(" %c", &seed_name);
    if (seed_name >= 'a' && seed_name <= 'z') {
        while (y > 0) {
            if (seed_collection[x].name == seed_name) {
                printf("There are %d seeds with the name '%c'\n",
                       seed_collection[x].amount, seed_collection[x].name);
                i = 1;
                break;
            }
            x++;
            y--;
        }
        if (i == 0) {
            printf("There is no seed with the name '%c'\n", seed_name);
        }
    } else {
        printf("Seed name has to be a lowercase letter \n");
    }
}

//use this function can move the position when the direction the same.
struct farmer no_direction_change(struct farmer cse_farmer, char direction) {
    if (direction == 'v') {
        if (cse_farmer.curr_row < 7) {
            cse_farmer.curr_row += 1;
        } else {
            cse_farmer.curr_row = 7;
        }
    } else if (direction == '<') {
        if (cse_farmer.curr_col > 0) {
            cse_farmer.curr_col -= 1;
        } else {
            cse_farmer.curr_col = 0;
        }
    } else if (direction == '>') {
        if (cse_farmer.curr_col < 7) {
            cse_farmer.curr_col += 1;
        } else {
            cse_farmer.curr_col = 7;
        }
    } else if (direction == '^') {
        if (cse_farmer.curr_row > 0) {
            cse_farmer.curr_row -= 1;
        } else {
            cse_farmer.curr_row = 0;
        }
    }

    return cse_farmer;
}

//change the farmer direction
struct farmer direction_change(struct farmer cse_farmer, char direction) {
    if (cse_farmer.curr_dir == direction) {
        cse_farmer = no_direction_change(cse_farmer, direction);
    } else {
        cse_farmer.curr_dir = direction;
    }
    return cse_farmer;
}

//water the land or plant seeds
void attending_adjacent_land(
        struct farmer cse_farmer, struct land farm[LAND_SIZE][LAND_SIZE],
        struct seeds seed_collection[MAX_NUM_SEED_TYPES], int types) {
    int y = types;
    int x = 0;
    int i = 0;
    char state;
    char seed_name;
    scanf(" %c", &state);
    if (state == 'w') {
        if (cse_farmer.curr_dir == '^' && cse_farmer.curr_col >= 0) {
            farm[cse_farmer.curr_row - 1]
            [cse_farmer.curr_col].is_watered = TRUE;
        } else if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col < 7) {
            farm[cse_farmer.curr_row]
            [cse_farmer.curr_col + 1].is_watered = TRUE;
        } else if (cse_farmer.curr_dir == '<' && cse_farmer.curr_row >= 0) {
            farm[cse_farmer.curr_row]
            [cse_farmer.curr_col - 1].is_watered = TRUE;
        } else if (cse_farmer.curr_dir == 'v' && cse_farmer.curr_row < 7) {
            farm[cse_farmer.curr_row + 1]
            [cse_farmer.curr_col].is_watered = TRUE;
        }
    } else if (state == 'p') {
        scanf(" %c", &seed_name);
        if (seed_name >= 'a' && seed_name <= 'z') {
            while (y > 0) {
                if (seed_collection[x].name == seed_name &&
                    seed_collection[x].amount > 0) {
                    if (cse_farmer.curr_dir == '^' &&
                        cse_farmer.curr_col >= 0) {
                        farm[cse_farmer.curr_row - 1]
                        [cse_farmer.curr_col].seed_name = seed_name;
                    } else if (cse_farmer.curr_dir == '>' &&
                               cse_farmer.curr_col < 7) {
                        farm[cse_farmer.curr_row]
                        [cse_farmer.curr_col + 1].seed_name = seed_name;
                    } else if (cse_farmer.curr_dir == '<' &&
                               cse_farmer.curr_row >= 0) {
                        farm[cse_farmer.curr_row]
                        [cse_farmer.curr_col - 1].seed_name = seed_name;
                    } else if (cse_farmer.curr_dir == 'v' &&
                               cse_farmer.curr_row < 7) {
                        farm[cse_farmer.curr_row + 1]
                        [cse_farmer.curr_col].seed_name = seed_name;
                    }
                    i = 1;
                    seed_collection[x].amount -= 1;
                    break;
                }
                x++;
                y--;
            }
            if (i == 0) {
                printf("There is no seed with the name '%c'\n",
                       seed_name);
            }
        } else {
            printf("Seed name has to be a lowercase letter \n");
        }
    }
}

//Plant a row of seeds or a line of seeds
void planting_multiple_seeds(
        struct farmer cse_farmer, struct land farm[LAND_SIZE][LAND_SIZE],
        struct seeds seed_collection[MAX_NUM_SEED_TYPES], int types) {
    int y = types;
    int x = 0;
    int i = 0;
    int distance = 0;
    char seed_name;
    scanf(" %c", &seed_name);
    if (seed_name >= 'a' && seed_name <= 'z') {
        while (y > 0) {
            if (seed_collection[x].name ==
                seed_name && seed_collection[x].amount > 0) {
                while (cse_farmer.curr_dir == '>' &&
                       (cse_farmer.curr_col + distance) < 8 &&
                       seed_collection[x].amount > 0) {
                    farm[cse_farmer.curr_row]
                    [cse_farmer.curr_col + distance].seed_name = seed_name;
                    distance++;
                    i = 1;
                    seed_collection[x].amount -= 1;
                }
                while (cse_farmer.curr_dir == 'v' &&
                       cse_farmer.curr_row + distance < 8 &&
                       seed_collection[x].amount > 0) {
                    farm[cse_farmer.curr_row + distance]
                    [cse_farmer.curr_col].seed_name = seed_name;
                    distance++;
                    i = 1;
                    seed_collection[x].amount -= 1;
                }
                while (cse_farmer.curr_dir == '<' || cse_farmer.curr_dir == '^') {
                    printf("  You cannot scatter seeds ^ or <\n");
                    i = 1;
                    break;
                }
            }
            x++;
            y--;
        }
        if (i == 0) {
            printf("There is no seed with the name '%c'\n", seed_name);
        }
    } else {
        printf("Seed name has to be a lowercase letter \n");
    }
}

//square area watering with input size
void square_watering(struct farmer cse_farmer,
                     struct land farm[LAND_SIZE][LAND_SIZE]) {
    int size;
    scanf(" %d", &size);
    int row = cse_farmer.curr_row;
    int col = cse_farmer.curr_col;
    int move_row = cse_farmer.curr_row - size;
    int move_col;
    if (size < 0) {
        printf("The size argument needs to be a non-negative integer\n");
    }
    while (move_row >= row - size && move_row <= row + size) {
        move_col = cse_farmer.curr_col - size;
        while (move_col >= col - size && move_col <= col + size) {
            if (move_row >= 0 && move_row <= 7 &&
                move_col >= 0 && move_col <= 7) {
                farm[move_row][move_col].is_watered = TRUE;
            }
            move_col++;
        }
        move_row++;
    }
}

//start a new day and have some change on the land
int new_day(struct land farm[LAND_SIZE][LAND_SIZE],
            struct farmer *cse_farmer, int day) {
    day += 1;
    int length;
    int height = 0;
    *cse_farmer = initialise_farmer(*cse_farmer);

    while (height < LAND_SIZE) {
        length = 0;
        while (length < LAND_SIZE) {
            if (farm[height][length].seed_name >= 'a'
                && farm[height][length].seed_name <= 'z' &&
                farm[height][length].is_watered == TRUE) {
                farm[height][length].seed_name -= 32;
                farm[height][length].is_watered = FALSE;
            } else {
                farm[height][length].seed_name = NO_SEED;
                farm[height][length].is_watered = FALSE;
            }
            length++;
        }
        height++;
    }

    return day;
}

//harvesting the seed and get five seeds corresponding to the letter
void harvesting_adjacent_land(struct land farm[LAND_SIZE][LAND_SIZE],
                              struct farmer cse_farmer, int seed_types,
                              struct seeds seed_collection[MAX_NUM_SEED_TYPES]) {
    int y = seed_types;
    int x = 0;
    char harvest_seed_name = NO_SEED;
    char harvested_seed_name = NO_SEED;

    if (cse_farmer.curr_dir == '^' && cse_farmer.curr_col >= 0) {
        harvest_seed_name = farm[cse_farmer.curr_row - 1]
        [cse_farmer.curr_col].seed_name;
        farm[cse_farmer.curr_row - 1]
        [cse_farmer.curr_col].seed_name = NO_SEED;
    } else if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col < 7) {
        harvest_seed_name = farm[cse_farmer.curr_row]
        [cse_farmer.curr_col + 1].seed_name;
        farm[cse_farmer.curr_row]
        [cse_farmer.curr_col + 1].seed_name = NO_SEED;
    } else if (cse_farmer.curr_dir == '<' && cse_farmer.curr_row >= 0) {
        harvest_seed_name = farm[cse_farmer.curr_row]
        [cse_farmer.curr_col - 1].seed_name;
        farm[cse_farmer.curr_row]
        [cse_farmer.curr_col - 1].seed_name = NO_SEED;
    } else if (cse_farmer.curr_dir == 'v' && cse_farmer.curr_row < 7) {
        harvest_seed_name = farm[cse_farmer.curr_row + 1]
        [cse_farmer.curr_col].seed_name;
        farm[cse_farmer.curr_row + 1]
        [cse_farmer.curr_col].seed_name = NO_SEED;
    }
    harvested_seed_name = harvest_seed_name + 'a' - 'A';
    if (harvested_seed_name >= 'a' && harvested_seed_name <= 'z') {
        while (y > 0) {
            if (seed_collection[x].name == harvested_seed_name) {
                seed_collection[x].amount += 5;
                break;
            }
            x++;
            y--;
        }
    }
    printf("  Plant '%c' was harvested, resulting in 5 'a' seed(s)\n",
           harvest_seed_name);
}

//trading seeds you want(only lower letter seeds)
int seeds_trading(struct seeds seed_collection[MAX_NUM_SEED_TYPES],
                  int types) {
    char change_seed_name;
    int trade_number;
    char want_trade_name;
    int y = types;
    int j = types;
    int seed_index = 0;
    int x = 0;
    int i = 0;
    int decide = 0;
    int seed_correct = 0;
    scanf(" %c %d %c", &change_seed_name, &trade_number,
          &want_trade_name);

    if (want_trade_name >= 'A' && want_trade_name <= 'Z') {
        printf("Seed name has to be a lowercase letter\n");
        return types;
    }
    if (trade_number < 0) {
        printf("  You can't trade negative seeds\n");
    } else if (change_seed_name >= 'a' && change_seed_name <= 'z') {
        while (y > 0) {
            if (seed_collection[x].name == change_seed_name
                && seed_collection[x].amount >= trade_number &&
                trade_number >= 0) {
                seed_collection[x].amount -= trade_number;
                while (j > 0) {
                    if (seed_collection[seed_index].name == want_trade_name) {
                        seed_collection[seed_index].amount += trade_number;
                        decide = 1;
                        break;
                    }
                    seed_index++;
                    j--;
                }
                if (decide == 0) {
                    seed_collection[types].name = want_trade_name;
                    seed_collection[types].amount += trade_number;
                    types += 1;
                }
                i = 1;
                break;
            } else if (seed_collection[x].amount < trade_number
                       && trade_number >= 0) {
                printf("  You don't have enough seeds to be traded\n");
                seed_correct = 1;
                break;
            } else if (trade_number < 0) {
                printf("  You can't trade negative seeds\n");
            }
            x++;
            y--;
        }
        if (i == 0 && seed_correct == 0) {
            printf("  You don't have the seeds to be traded\n");
        }
    } else {
        printf("Seed name has to be a lowercase letter \n");
    }
    return types;
}

//find the 3x3 area plant number at the position
void get_around_plants(struct land farm[LAND_SIZE][LAND_SIZE],
                       struct plant_num plant_number[LAND_SIZE][LAND_SIZE]) {
    int x;
    int y;
    int plant_numbers;
    int row = 0;
    int line;
    while (row < LAND_SIZE) {
        line = 0;
        while (line < LAND_SIZE) {
            x = -1;
            plant_numbers = 0;
            while (x < 2) {
                y = -1;
                while (y < 2) {
                    if (row + x >= 0 && row + x <= 7 &&
                        line + y >= 0 && line + y <= 7) {
                        if (farm[row + x][line + y].seed_name != NO_SEED) {
                            plant_numbers++;

                        }
                    }
                    y++;
                }
                x++;
            }
            plant_number[row][line].number = plant_numbers;
            line++;
        }
        row++;
    }
}

//the natural disasters change the land plant
void natural_disasters(struct land farm[LAND_SIZE][LAND_SIZE],
                       struct plant_num plant_number[LAND_SIZE][LAND_SIZE]) {
    get_around_plants(farm, plant_number);

    char weather;
    int survive_plant;
    int x = 0;
    int y;
    scanf(" %c", &weather);
    scanf(" %d", &survive_plant);
    if (weather == 'w') {
        while (x < LAND_SIZE) {
            y = 0;
            while (y < LAND_SIZE) {
                if (plant_number[x][y].number <= survive_plant) {
                    farm[x][y].seed_name = NO_SEED;
                }
                y++;
            }
            x++;
        }
    }
    if (weather == 'd') {
        while (x < LAND_SIZE) {
            y = 0;
            while (y < LAND_SIZE) {
                if (plant_number[x][y].number > survive_plant) {
                    farm[x][y].seed_name = NO_SEED;
                }
                y++;
            }
            x++;
        }
    }
}















