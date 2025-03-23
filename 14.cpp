//
// Created by kalle on 23/03/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

int main() {
  char filename[100];
  char lines[MAX_LINES][MAX_LENGTH];
  FILE *file;
  int count = 0;

  printf("Enter filename: ")
  scanf("%s", filename);
  file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return 1;
  }

  printf("Reading file...\n");
  while (count < MAX_LINES && fgets(lines[count], MAX_LENGTH, file)) {
    lines[count][strcspn(lines[count], "\n")] = 0;
    count++;
  }
  fclose(file);

  for (int i = 0; i < count; i++) {
    for (int j = 0; lines[i][j] != '\0'; j++) {
      lines[i][j] = toupper((unsigned char)lines[i][j]);
    }
  }

  file = fopen(filename, "w");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return 1;
  }

  printf("\nWriting modified lines back into file...\n");
  for (int i = 0; i < count; i++) {
    fprintf(file, "%s\n", lines[i]);
  }
  fclose(file);

  printf("\nOperation completed successfully, modified content has been saved");

  return 0;
}