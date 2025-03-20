//
// Created by kalle on 18/03/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_menu();
int roll_die(int sides);
int get_valid_choice(int low, int high);

int main() {
  srand(time(NULL));

  int choice;
  do {
    display_menu();
    choice = get_valid_choice(1, 3);

    switch (choice) {
      case 1:
        printf("You rolled a D6: %d\n", roll_die(6));
        break;
      case 2:
        printf("You rolled a D10: %d\n", roll_die(10));
        break;
      case 3:
        printf("Exiting. Have a good day!\n");
        break;
      default:
        printf("Unexpected error. Try again.\n");
        break;
    }
  } while (choice != 3);

  return 0;
}

void display_menu() {
  printf("1. Roll D6\n");
  printf("2. Roll D10\n");
  printf("3. Exit\n");
  printf("Choice: ");
}

int roll_die(int sides) {
  return (rand() % sides) + 1;
}

int get_valid_choice(int low, int high) {
  int choice;
  while (1) {
    if (scanf("%d", &choice) == 1 && choice >= low && choice <= high) {
      break;
    } else {
      printf("Invalid input. Enter a number between %d and %d.\n", low, high);
      while (getchar() != '\n');
    }
  }
  return choice;
}
