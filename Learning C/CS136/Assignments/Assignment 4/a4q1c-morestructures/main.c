/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

//
// Name: Yiyan
// login ID: y84huang
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"
#include "topping.h" // we have not yet discussed include statements. 
              // This is needed here if we are to provide you with a 
              // correct implementation of the functions discussed in 
              // the previous two subproblems. 

const int MAX_TOPPINGS = 5;
const int PRICE_PER_SCOOP = 400;

/*
 * The price_list structure is used to store the toppings 
 * available at our store.
 * Since we have not yet learned C features such as arrays
 * and dynamic memory, the structure limits the store to
 * at most five toppings.
 */
struct price_list{
  struct topping t1;
  struct topping t2;
  struct topping t3;
  struct topping t4;
  struct topping t5;
};

/*
 * The icecream_order structure will represent a customer's order.
 * Once again we are unable to use some useful C features such as
 * arrays and heap memory which force us to limit the poor
 * customer to a maximum of MAX_TOPPINGS toppings.
 */
struct icecream_order {
    int num_scoops; // number of scoops
    int num_toppings;   // number of toppings added
                        // We limit this between 0 and MAX_TOPPINGS
    const struct topping *topping_1;
    const struct topping *topping_2;
    const struct topping *topping_3;
    const struct topping *topping_4;
    const struct topping *topping_5;
};



// create_empty_price_list() initializes a new price_list using the 
//   topping initialization function for each topping
struct price_list create_empty_price_list() {
  struct price_list list = { topping_init(), 
    topping_init(), topping_init(), topping_init(), topping_init() };
  return list;
}

/////////////////////////////////////////////////////////
/////////// DO NOT MODIFY ANY CODE ABOVE THIS ///////////
/// YOU MUST OF COURSE UPDATE THE INTEGRITY STATEMENT ///
/////////////////////////////////////////////////////////


// read_prict_list(list) will use the read_topping function to read 
//   five toppings and sequentially update the toppings in *list. 
//   If reading a topping fails, no further toppings are read. 
// effects: may update list
// requires: list is not NULL
void read_price_list(struct price_list *list) {
  // your implementation comes here
  assert(list != NULL);
  
  int tally = 0;
  
  while (tally < 5) {
    if (tally == 0 ) {
      if ( read_topping(&list->t1) ) {
        tally += 1;
      } else {
        break;
      }
    } else if ( tally == 1 ) {
      if ( read_topping(&list->t2) ) {
        tally += 1;
      } else {
        break;
      }
    } else if ( tally == 2 ) {
      if ( read_topping(&list->t3) ) {
        tally += 1;
      } else {
        break;
      }
    } else if ( tally == 3 ) {
      if ( read_topping(&list->t4) ) {
        tally += 1;
      } else {
        break;
      }
    } else if ( tally == 4 ) {
      if ( read_topping(&list->t5) ) {
        tally += 1;
      } else {
        break;
      }
    }
  }
}

// print_price_list(list) prints the list using the print functions for toppings
// effects: may produce output
// requires: list is not NULL
void print_price_list(const struct price_list *list) {
  // your implementation comes here
  assert(list != NULL);
  
  print_topping(&list->t1);
  print_topping(&list->t2);
  print_topping(&list->t3);
  print_topping(&list->t4);
  print_topping(&list->t5);
}

// find_topping(list,name) returns a pointer to a topping with the 
//   name "name" if it is found in the list, otherwise returns NULL
// requires: list is not NULL
const struct topping *find_topping(const struct price_list *list, const char name){
  // your implementation comes here
  assert(list != NULL);
  if (name == list->t1.name) {
    return &list->t1;
  } else if (name == list->t2.name) {
    return &list->t2;
  } else if (name == list->t3.name) {
    return &list->t3;
  } else if (name == list->t4.name) {
    return &list->t4;
  } else if (name == list->t5.name) {
    return &list->t5;
  } else {
    return NULL;
  }
}

// start_order(num_scoops) returns a new icecream_order with the number of 
//   scoops set to num_scoops and no toppings added
struct icecream_order start_order(const int num_scoops) {
    struct icecream_order new_order = 
      { num_scoops, 0, NULL, NULL, NULL, NULL, NULL};
    return new_order;
}

// add_topping(order,list,name) adds a topping with the name "name" to 
//   *order if the store carries the topping with this 
//   name and there is space to add a new topping.
//   The function has no effect if the topping is not available at the 
//   store or there is no room for additional toppings. 
//   If a topping is added, the order is updated accordingly.
// requires: order and list are not NULL,
//   *order contains a positive number of scoops of ice cream
// effects: may mutate *order
void add_topping(struct icecream_order *order, 
                 const struct price_list *list, const char name){
  // your implementation comes here
  assert(order != NULL && list != NULL && order->num_scoops > 0);
  assert(order->num_toppings <= 5);
  
  if (order->num_toppings == 0) {
    order->topping_1 = find_topping(list, name);
    order->num_toppings += 1;
  } else if (order->num_toppings == 1) {
    order->topping_2 = find_topping(list, name);
    order->num_toppings += 1;
  } else if (order->num_toppings == 2) {
    order->topping_3 = find_topping(list, name);
    order->num_toppings += 1;
  } else if (order->num_toppings == 3) {
    order->topping_4 = find_topping(list, name);
    order->num_toppings += 1;
  } else {
    order->topping_5 = find_topping(list, name);
    order->num_toppings += 1;
  }
}

// print_order(order) prints the current icecream order based on the 
//   following format:
//   First line uses the format string: 
//    "Scoops: %d Price: %d\n" where the price printed is the price for that 
//     many scoops of ice cream using PRICE_PER_SCOOP
//   Second line follows the format string: "Toppings: \n"
//   This is followed by between 0 to 5 lines that are produced by using the 
//    print_topping function to print toppings in this order.
//   The final line follows the format string: "Total Price: %d\n" and prints 
//   the calculated total price of the icecream order which is the sum of the 
//   price for the scoops of icecream and all the toppings added to the order
// requires : number of scoops in order is greater than 0 
//            (you cannot just order toppings!)
// requires: order is not NULL
void print_order(const struct icecream_order *order) {
  assert(order->num_scoops > 0);
  assert(order != NULL);
  
  printf("Scoops: %d Price: %d\n", order->num_scoops, 
  order->num_scoops * PRICE_PER_SCOOP);
  printf("Toppings: \n");
  
  int total_price = order->num_scoops * PRICE_PER_SCOOP;
  
  if ( order->topping_1 != NULL ) {
    total_price += order->topping_1->price;
    print_topping(order->topping_1);
  } if ( order->topping_2 != NULL ) {
    total_price += order->topping_2->price;
    print_topping(order->topping_2);
  } if ( order->topping_3 != NULL ) {
    total_price += order->topping_3->price;
    print_topping(order->topping_3);
  } if ( order->topping_4 != NULL ) {
    total_price += order->topping_4->price;
    print_topping(order->topping_4);
  } if ( order->topping_5 != NULL ) {
    total_price += order->topping_5->price;
    print_topping(order->topping_5);
  }
  
  printf("Total Price: %d\n", total_price);
}



/////////////////////////////////////////////////////////
/////////// DO NOT MODIFY ANY CODE BELOW THIS ///////////
/////////////////////////////////////////////////////////

// This is the icecream ordering program that also
// acts as a test harness
// Be sure to understand how this function works as 
// you will need to understand it to test your implementation
int main(void) {
  struct price_list list = create_empty_price_list();
  char command = '\0';
  struct icecream_order order;
  while(true) {
    printf("Type a command: (r, p, o, t, e, q)\n");
    scanf(" %c",&command);
    if (command == 'r') { // read a price list
        printf("Reading price list.\n");
        read_price_list(&list);
    } else if (command == 'p') {
        // price list must already have been created
        printf("Printing price list.\n"); // print the price list
        print_price_list(&list);
    } else if (command == 'o') { // order an ice cream
        printf("How many scoops in your ice cream order?\n");
        int scoops = -1;
        scanf("%d",&scoops);
        order = start_order(scoops);
    } else if (command == 't') { // add a topping
        // should only be used if 
        // - an ice cream order has been started
        // - a price_list read
        printf("Which topping would you like to add?\n");
        char topping = INVALID_TOPPING;
        scanf(" %c",&topping);
        add_topping(&order,&list,topping);
    } else if (command == 'e') { // e as in ready to EAT ice cream
        printf("Printing order:\n");
        print_order(&order);
    } else if (command == 'q') { // quit the program
        return 0;
    } else {
        printf("Invalid command: %c.\n",command);
    }
  }
}