//
// Created by kalle on 07/02/2025.
//
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define SIZE 20

int find_first(const unsigned int *array, unsigned int hello) {
  int index = 0;
  while (array[index] != 0) {
    if (array[index] == hello) {
      return index;
    }
    index++;
  }
  return -1;
}

int main() {
  unsigned int numbers[SIZE];

  srand(time(NULL));

  for (int i = 0; i < SIZE -1; i++) {
    numbers[i] = (rand() % 20) + 1;
  }
  numbers[SIZE - 1] = 0;

  printf("Generated numbers:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%u\n", numbers[i]);
  }

  unsigned int search;
  while (1) {
    printf("Enter number to search (0 to quit):\n ");
    scanf("%u", &search);

    if (search == 0) {
      printf("Thank you and goodbye!\n");
      break;
    }

    int index = find_first(numbers, search);
    if (index == -1) {
      printf("Number %u not found. :(\n", search);
    } else {
      printf("Number %u found at index %d.\n", search, index);
    }
  }
  return 0;
}