//
// Created by kalle on 07/02/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void print_numbers(const int *array, int count) {
  for (int i = 0; i < count; i++) {
    printf("%8d\n", array[i]);
  }
}

int main() {
  int numbers[SIZE];

  srand(time(NULL));
  for (int i = 0; i < SIZE; i++) {
    numbers[i] = rand() % 100;
  }

  printf("Generated numbers:\n");
  print_numbers(numbers, SIZE);

  return 0;
}