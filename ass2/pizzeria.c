// z5339245 Leslie
// pizzeria.c
// 17/11/2021
//this is a complete pizza work
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pizzeria.h"
#include "save_string.h"

struct ingredient {
    char ingredient_name[30];
    int amount;
    double price;
    struct ingredient *next;
};

struct stock {
    struct stock *next;
    struct ingredient *ingredient;
};

struct order {
    char customer[30];
    char pizza[30];
    double price;
    int time;
    struct order *next;
    struct ingredient *ingredient;
    struct order *select;
};

struct pizzeria {
    struct order *orders;
    struct order *select;
    struct stock *stock;
};


// Prints a single order
void print_order(
        int num,
        char *customer,
        char *pizza_name,
        double price,
        int time_allowed
);


void print_ingredient(char *name, int amount, double price);

int determine_amount_enough(struct ingredient *stock_i, struct ingredient *select_i);

void delete_ingredient(struct ingredient *stock_i,
                       struct ingredient *select_i,
                       struct pizzeria *pizzeria);

void delete_stock(struct ingredient *stock_i, struct pizzeria *pizzeria);

//creat a new pizzeria and initialize a variable
struct pizzeria *create_pizzeria() {

    struct pizzeria *new = malloc(sizeof(struct pizzeria));

    new->orders = NULL;
    new->select = NULL;
    new->stock = NULL;

    return new;
}

// add new order in the pizzeria
int add_order(
        struct pizzeria *pizzeria,
        char *customer,
        char *pizza_name,
        double price,
        int time_allowed
) {
    //the incorrect output
    if (price < 0) {
        return INVALID_PRICE;
    }
    if (time_allowed < 0) {
        return INVALID_TIME;
    }

    struct order *new = NULL;
    struct order *new2 = NULL;
    new = pizzeria->orders;

    if (new == NULL) {
        new = malloc(sizeof(struct order));
        strcpy(new->customer, customer);
        strcpy(new->pizza, pizza_name);
        new->price = price;
        new->time = time_allowed;
        new->next = NULL;
        pizzeria->orders = new;
        pizzeria->orders->ingredient = NULL;

    } else {
        while (new->next != NULL) {
            new = new->next;
        }
        new2 = malloc(sizeof(struct order));
        strcpy(new2->customer, customer);
        strcpy(new2->pizza, pizza_name);
        new2->price = price;
        new2->time = time_allowed;
        new2->next = NULL;
        new2->ingredient = NULL;
        new->next = new2;

    }
    return SUCCESS;
}

//print all order and call the print select function
void print_all_orders(struct pizzeria *pizzeria) {
    int number = 1;
    struct order *new = pizzeria->orders;
    while (new != NULL) {
        printf("0%d: %s ordered a %s pizza ($%.2f) due in %d minutes.\n",
               number, new->customer, new->pizza,
               new->price, new->time);
        number++;
        new = new->next;

    }
    print_selected_order(pizzeria);
    return;
}

//find the shortest time in all order and return it
int next_deadline(struct pizzeria *pizzeria) {
    int lowest_time = 100;
    struct order *new = pizzeria->orders;
    if (new == NULL) {
        return INVALID_CALL;
    } else {
        while (new != NULL) {
            if (new->time < lowest_time) {
                lowest_time = new->time;
            }
            new = new->next;
        }
    }
    return lowest_time;
}

//select new order if choose the last order will choose null
void select_next_order(struct pizzeria *pizzeria) {

    struct order *new_o = pizzeria->orders;

    if (pizzeria->select == NULL) {
        pizzeria->select = new_o;
    } else {
        while (new_o != pizzeria->select) {
            new_o = new_o->next;
        }
        pizzeria->select = new_o->next;
    }

    return;
}

//select new order if choose the first order will choose null
void select_previous_order(struct pizzeria *pizzeria) {
    struct order *new_o = pizzeria->orders;

    if (pizzeria->select == NULL) {
        while (new_o->next != NULL) {
            new_o = new_o->next;
        }
        pizzeria->select = new_o;
    } else if (new_o == pizzeria->select) {
        pizzeria->select = NULL;
    } else {
        while (new_o->next != pizzeria->select) {
            new_o = new_o->next;
        }
        pizzeria->select = new_o;
    }

    return;
}

//print the selected order and print the ingredient
void print_selected_order(struct pizzeria *pizzeria) {
    struct order *new_o = pizzeria->select;

    if (new_o != NULL) {
        printf("\nThe selected order is %s's %s pizza ($%.2f) due in %d minutes.\n",
               new_o->customer, new_o->pizza,
               new_o->price, new_o->time);
        struct ingredient *new_i = pizzeria->select->ingredient;
        while (new_i != NULL) {
            printf("%s: %d @ $%.2f\n", new_i->ingredient_name,
                   new_i->amount, new_i->price);
            new_i = new_i->next;
        }
    } else {
        printf("\nNo selected order.\n");
    }
}

//add ingredient in select order
int add_ingredient(
        struct pizzeria *pizzeria,
        char *ingredient_name,
        int amount,
        double price
) {
    int state = 0;
    int times = 0;
    struct ingredient *new = pizzeria->select->ingredient;
    struct ingredient *new1 = NULL;
    struct ingredient *new2 = NULL;
    struct ingredient *new3 = NULL;

    if (pizzeria->select == NULL) {
        return INVALID_ORDER;
    }
    if (price < 0) {
        return INVALID_PRICE;
    }
    if (amount < 0) {
        return INVALID_AMOUNT;
    }

    //if order is null insert
    if (new == NULL) {
        new = malloc(sizeof(struct ingredient));
        new->price = price;
        strcpy(new->ingredient_name, ingredient_name);
        new->amount = amount;
        new->next = NULL;
        pizzeria->select->ingredient = new;
    } else {
        new = pizzeria->select->ingredient;
        while (new != NULL) {
            if (strcmp(ingredient_name, new->ingredient_name) == 0) {
                state = 1;
                break;
            }
            if ((strcmp(ingredient_name, new->ingredient_name)) < 0) {
                state = 2;
                break;
            }
            if (new->next == NULL) {
                break;
            }
            times += 1;
            new = new->next;
        }

        //insert the same
        if (state == 1) {
            new->amount += amount;
            state = 3;
        }

        //insert tail
        if (state == 0 && (strcmp(ingredient_name, new->ingredient_name)) > 0) {

            new1 = malloc(sizeof(struct ingredient));

            strcpy(new1->ingredient_name, new->ingredient_name);
            new1->amount = new->amount;
            new1->price = new->price;
            new->next = new1;
            new = new->next;
            strcpy(new->ingredient_name, ingredient_name);
            new->amount = amount;
            new->price = price;
            new->next = NULL;
        }

        //insert head
        if ((new == pizzeria->select->ingredient) && state != 3) {

            new1 = malloc(sizeof(struct ingredient));

            strcpy(new1->ingredient_name, ingredient_name);
            new1->amount = amount;
            new1->price = price;
            new1->next = new;
            pizzeria->select->ingredient = new1;
            state = 3;
        }

        //insert middle
        if (state == 2) {
            int x = 0;
            new3 = malloc(sizeof(struct ingredient));
            new2 = pizzeria->select->ingredient;

            while (times - 1 > x) {
                new2 = new2->next;
                x++;
            }
            new3->price = price;
            strcpy(new3->ingredient_name, ingredient_name);
            new3->amount = amount;
            new2->next = new3;
            new3->next = new;
        }
    }
    return SUCCESS;
}

//calculate the total profit
double calculate_total_profit(struct pizzeria *pizzeria) {
    if (pizzeria->select == NULL) {
        return INVALID_ORDER;
    }
    struct order *new = pizzeria->select;
    struct ingredient *new_i = pizzeria->select->ingredient;
    double total_profit = new->price;

    while (new_i != NULL) {
        total_profit -= new_i->price * new_i->amount;
        while (new_i->next == NULL) {
            break;
        }
        new_i = new_i->next;
    }

    return total_profit;
}

//cancel the select order and free it
int cancel_order(struct pizzeria *pizzeria) {
    if (pizzeria->select == NULL) {
        return INVALID_ORDER;
    }

    struct order *del = pizzeria->select;
    struct order *p = pizzeria->orders;

    if (p == del) {
        struct order *next = p->next;
        pizzeria->orders = next;
        pizzeria->select = pizzeria->select->next;
        return SUCCESS;
    }
    while (p->next != NULL) {
        if (p->next == del) {
            p->next = del->next;
            pizzeria->select = pizzeria->select->next;
            free(del);
            break;
        }
        p = p->next;
    }

    return SUCCESS;
}

//step by step free the all thing
void free_pizzeria(struct pizzeria *pizzeria) {
    struct order *p = NULL;
    struct ingredient *new_i = NULL;

    //free the stick
    if (pizzeria->stock != NULL) {
        while (pizzeria->stock->ingredient != NULL) {
            new_i = pizzeria->stock->ingredient->next;
            free(pizzeria->stock->ingredient);
            pizzeria->stock->ingredient = new_i;
        }
    }
    free(pizzeria->stock);
    pizzeria->stock = NULL;
    if (pizzeria->stock != NULL) {
        free(pizzeria->stock);
    }

    //free the pizzeria order
    while (pizzeria->orders != NULL) {
        while (pizzeria->orders->ingredient != NULL) {
            new_i = pizzeria->orders->ingredient->next;
            free(pizzeria->orders->ingredient);
            pizzeria->orders->ingredient = new_i;
        }
        p = pizzeria->orders->next;
        free(pizzeria->orders);
        pizzeria->orders = p;
    }
    free(pizzeria->orders);
    pizzeria->orders = NULL;

    free(pizzeria);
    pizzeria = NULL;

    return;
}

//make a ingredient stock
int refill_stock(
        struct pizzeria *pizzeria,
        char *ingredient_name,
        int amount,
        double price
) {
    int state = 0;
    int times = 0;
    struct ingredient *new = NULL;
    struct ingredient *new1 = NULL;
    struct ingredient *new2 = NULL;
    struct ingredient *new3 = NULL;


    if (price < 0) {
        return INVALID_PRICE;
    }
    if (amount <= 0) {
        return INVALID_AMOUNT;
    }

    struct ingredient *new_i = NULL;
    struct stock *new_s = NULL;


    if (pizzeria->stock == NULL) {
        new_s = malloc(sizeof(struct stock));

        new_i = malloc(sizeof(struct ingredient));
        strcpy(new_i->ingredient_name, ingredient_name);
        new_i->amount = amount;
        new_i->price = price;
        new_i->next = NULL;
        new_s->ingredient = new_i;
        pizzeria->stock = new_s;
    } else {
        new = pizzeria->stock->ingredient;

        while (new != NULL) {
            if (strcmp(ingredient_name, new->ingredient_name) == 0) {
                state = 1;
                break;
            }
            if ((strcmp(ingredient_name, new->ingredient_name)) < 0) {
                state = 2;
                break;
            }
            if (new->next == NULL) {
                break;
            }
            times += 1;
            new = new->next;
        }

        //insert the same
        if (state == 1) {
            new->amount += amount;
            state = 3;
        }

        //insert tail
        if (state == 0 && (strcmp(ingredient_name, new->ingredient_name)) > 0) {

            new1 = malloc(sizeof(struct ingredient));

            strcpy(new1->ingredient_name, new->ingredient_name);
            new1->amount = new->amount;
            new1->price = new->price;
            new->next = new1;
            new = new->next;
            strcpy(new->ingredient_name, ingredient_name);
            new->amount = amount;
            new->price = price;
            new->next = NULL;
        }

        //insert head
        if ((new == pizzeria->stock->ingredient) && state != 3) {

            new1 = malloc(sizeof(struct ingredient));

            strcpy(new1->ingredient_name, ingredient_name);
            new1->amount = amount;
            new1->price = price;
            new1->next = new;
            pizzeria->stock->ingredient = new1;
            state = 3;
        }

        //insert middle
        if (state == 2) {
            int x = 0;
            new3 = malloc(sizeof(struct ingredient));
            new2 = pizzeria->stock->ingredient;

            while (times - 1 > x) {
                new2 = new2->next;
                x++;
            }
            new3->price = price;
            strcpy(new3->ingredient_name, ingredient_name);
            new3->amount = amount;
            new2->next = new3;
            new3->next = new;
        }
    }
    return SUCCESS;
}

//print all the stock
void print_stock(struct pizzeria *pizzeria) {
    struct ingredient *new_i = NULL;
    struct stock *new_s = pizzeria->stock;
    printf("The stock contains:\n");
    if (new_s != NULL) {
        new_i = new_s->ingredient;
        while (new_i != NULL) {
            printf("%s: %d @ $%.2f\n", new_i->ingredient_name,
                   new_i->amount, new_i->price);
            new_i = new_i->next;
        }
    }
    return;
}

//Determine if the order can be completed
int can_complete_order(struct pizzeria *pizzeria) {
    int state;
    if (pizzeria->select == NULL || pizzeria->select->ingredient == NULL) {
        return INVALID_ORDER;
    }
    if (pizzeria->stock == NULL) {
        return INSUFFICIENT_STOCK;
    }
    struct order *select_o = pizzeria->select;
    struct ingredient *select_i;
    struct ingredient *stock_i = NULL;
    if (select_o != NULL) {
        select_i = select_o->ingredient;
        while (select_i != NULL) {
            stock_i = pizzeria->stock->ingredient;
            state = determine_amount_enough(stock_i, select_i);

            if (state == 0) {
                return INSUFFICIENT_STOCK;
            }
            select_i = select_i->next;
        }
    }

    return SUCCESS;
}

//complete the other and delete the order
int complete_order(struct pizzeria *pizzeria) {

    if (pizzeria->select == NULL || pizzeria->select->ingredient == NULL) {
        return INVALID_ORDER;
    }
    if (pizzeria->stock == NULL) {
        return INSUFFICIENT_STOCK;
    }
    struct order *select_o = pizzeria->select;
    struct order *select_o_next = pizzeria->orders;
    struct order *select_o_original = pizzeria->orders;
    struct ingredient *select_i = select_o->ingredient;
    struct ingredient *stock_i = NULL;

    if (can_complete_order(pizzeria) == SUCCESS) {
        delete_ingredient(stock_i, select_i, pizzeria);

        stock_i = pizzeria->stock->ingredient;

        delete_stock(stock_i, pizzeria);

        struct ingredient *order_i_1 = NULL;
        while (pizzeria->select->ingredient != NULL) {
            order_i_1 = pizzeria->select->ingredient->next;
            free(pizzeria->select->ingredient);
            pizzeria->select->ingredient = order_i_1;
        }

        if (strcmp(select_o_next->pizza, pizzeria->select->pizza) == 0) {
            if (select_o_next == pizzeria->orders) {
                select_next_order(pizzeria);
                pizzeria->orders = select_o_next->next;
            } else {
                select_next_order(pizzeria);
                select_o_original->next = select_o_next->next;
            }
            free(select_o_next);
        }

        return SUCCESS;
    } else {
        return INSUFFICIENT_STOCK;
    }
}

//save the ingredient with txt document
int save_ingredients(struct pizzeria *pizzeria, char *file_name) {
    if (pizzeria->select == NULL) {
        return INVALID_ORDER;
    }
    char array[MAX_SAVE_LENGTH] = {0};
    char array_total[MAX_SAVE_LENGTH] = {0};
    struct ingredient *new_i = pizzeria->select->ingredient;
    char name[100] = {0};
    int amount[20] = {0};
    int i = 0;
    int position_t = 0;
    int position_a;
    double price[20] = {0};


    while (new_i != NULL) {
        position_a = 0;
        strcpy(name, new_i->ingredient_name);
        amount[i] = new_i->amount;
        price[i] = new_i->price;
        sprintf(array, "%s %d %.2f\n", name, amount[i], price[i]);

        while (array[position_a] != '\n') {
            array_total[position_t] = array[position_a];
            position_a++;
            position_t++;
        }
        array_total[position_t] = '\n';
        position_t++;

        new_i = new_i->next;
        i++;
    }
    save_string(file_name, array_total);
    return SUCCESS;
}

//load the ingredient in select order
int load_ingredients(struct pizzeria *pizzeria, char *file_name) {
    if (pizzeria->select == NULL) {
        return INVALID_ORDER;
    }
    char array_total[MAX_SAVE_LENGTH] = {0};
    char array[MAX_SAVE_LENGTH] = {0};
    int position_t = 0;

    int position_a;
    int amount;
    double price;
    char name[30];

    char *pointer = load_string(file_name);

    strcpy(array_total, pointer);
    while (array_total[position_t] != '\0') {
        position_a = 0;
        while (array_total[position_t] != '\n') {
            array[position_a] = array_total[position_t];
            position_a++;
            position_t++;
        }
        position_t++;
        sscanf(array, "%s %d %lf", name, &amount, &price);

        add_ingredient(pizzeria, name, amount, price);
    }
    free(pointer);

    return SUCCESS;
}


void print_order(
        int num,
        char *customer,
        char *pizza_name,
        double price,
        int time_allowed
) {
    printf("%02d: %s ordered a %s pizza ($%.2lf) due in %d minutes.\n",
           num, customer, pizza_name, price, time_allowed);
    return;
}


void print_ingredient(char *name, int amount, double price) {
    printf("    %s: %d @ $%.2lf\n", name, amount, price);
}


int determine_amount_enough(struct ingredient *stock_i,
                            struct ingredient *select_i) {
    int state = 0;
    while (stock_i != NULL) {
        if (strcmp(stock_i->ingredient_name, select_i->ingredient_name) == 0) {
            state = 1;
            if (stock_i->amount < select_i->amount) {
                return 0;
            }
        }
        stock_i = stock_i->next;
    }
    return state;
}

//when order can complete delete the ingredient
void delete_ingredient(struct ingredient *stock_i,
                       struct ingredient *select_i,
                       struct pizzeria *pizzeria) {
    while (select_i != NULL) {
        stock_i = pizzeria->stock->ingredient;

        while (stock_i != NULL) {
            if (strcmp(stock_i->ingredient_name, select_i->ingredient_name) == 0) {
                stock_i->amount -= select_i->amount;
            }
            stock_i = stock_i->next;
        }
        select_i = select_i->next;

    }
}

//delete stock if ingredient amount is 0
void delete_stock(struct ingredient *stock_i, struct pizzeria *pizzeria) {
    struct ingredient *stock_i_2 = stock_i;
    while (stock_i != NULL) {
        if (stock_i->amount == 0) {
            if (stock_i == pizzeria->stock->ingredient) {
                pizzeria->stock->ingredient = stock_i->next;
                break;
            } else {
                stock_i_2->next = stock_i->next;
                break;
            }
        }
        stock_i_2 = stock_i;
        stock_i = stock_i->next;
    }
    free(stock_i);
}
