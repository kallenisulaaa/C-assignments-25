//
// Created by kalle on 23/03/2025.
//

#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl) {
  if (strlen(repl) != 2) {
    return 0;
  }

  char old_char = repl[0];
  char new_char = repl[1];
  int replace_count = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == old_char) {
      str[i] = new_char;
      replace_count++;
    }
  }
  return replace_count;
}

int main() {
  char text[80];
  char repl[3];

  printf("Enter a string (max 79 characters): ");
  fgets(text, sizeof(text), stdin);
  text[strcspn(text, "\n")] = '\0';

  printf("Enter two characters (e.g., 'e3'): ");
  fgets(repl, sizeof(repl), stdin);
  repl[strcspn(repl, "\n")] = '\0';

  int count = replace_char(text, repl);

  if (count > 0) {
    printf("\nModified string: %s\n", text);
    printf("Number of replaced characters: %d\n", count);
  } else {
    printf("String was not modified. Ensure your input is valid.\n");
  }
  return 0;
}