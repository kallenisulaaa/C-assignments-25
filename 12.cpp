//
// Created by kalle on 23/03/2025.
//
#include <stdio.h>
#include <string.h>

int count_words(const char* str, const char* word) {
  int count = 0;
  const char* pos = str;

  while ((pos = strstr(pos, word)) != NULL) {
    count++;
    pos += strlen(word);
  }
  return count;
}

int main() {
  char str[200];
  char word[50];

  printf("Welcome to word counter\n");

  while (1) {
    printf("\nPlease enter a string (max 199 chars): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter a word to search (type stop to exit): ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';

    if (strcmp(word, "stop") == 0) {
      printf("Exiting... Have a nice day!\n");
      break;
    }

    int count = count_words(str, word);
    printf("The word \"%s\" occurs %d times\n in the string", word, count);
  }
  return 0;
}