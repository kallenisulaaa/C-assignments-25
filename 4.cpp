//
// Created by kalle on 18/03/2025.
//

#include <stdio.h>

int read_integer() {
   int value;
   char c;
   while (1) {
     printf("Enter an integer: ");
     if (scanf("%d%c", &value, &c) == 2 && c == '\n') {
       return value;
     } else {
       printf("Invalid input, try again\n");
       while (getchar() != '\n');
     }
   }
}

int main() {
  int count = 0, sum = 0, number;

  printf("Enter positive numbers or a negative to stop.\n");

  while (1) {
    number = read_integer();
    if (number < 0) break;
    sum += number;
    count++;
  }

  if (count > 0) {
    double average = (double)sum / count;
    printf("You entered %d positive numbers. Average is %.3f.\n", count, average);
  } else {
    printf("No positive numbers entered.\n");
  }

  return 0;
}