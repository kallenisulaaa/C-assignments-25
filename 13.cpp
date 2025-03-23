//
// Created by kalle on 23/03/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main() {
  char filename[100];
  FILE *file;
  int num, count = 0, min = INT_MAX, max = INT_MIN;

  printf("Enter filename: ");
  scanf("%99s", filename);

  file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return 1;
  }

  printf("Reading data from file... \n");
  while (fscanf(file, "%d", &num) == 1) {
    count++;
    if (num < min) min = num;
    if (num > max) max = num;
  }

  if (count == 0) {
    printf("No valid integers found in the file. \n");
  } else {
    printf("Count of numbers: %d\n", count);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
  }

  fclose(file);
  return 0;
}