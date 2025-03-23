//
// Created by kalle on 23/03/2025.
//
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Welcome to the String Length Checker\n");

  while (1) {
    printf("Please enter a string (type stop to exit): ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "stop") == 0) {
      printf("Exiting. Have a nice day!\n");
      break;
    }

    printf("The length of the string is: %lu\n", strlen(input));
  }

  return 0;
}