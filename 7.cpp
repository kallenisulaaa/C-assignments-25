#include <cstdio>

bool read_positive(int *value) {
  int num;
  printf("Enter a positive number:\n");

  if (scanf("%d", &num) != 1) {
    while (getchar() != '\n');
    return false;
  }

  if (num > 0) {
    *value = num;
    return true;
  }

   return false;
}

int main() {
  int guess, invalid_attempts = 0;

  printf("Guess how much money I have?\n");

  while (invalid_attempts < 3) {
    if (read_positive(&guess)) {
      int claim = (guess * 2) + 20;
      printf("Wrong bubby. I have %d euro\n", claim);
    } else {
      printf("Invalid input\n");
      invalid_attempts++;
    }
    if (invalid_attempts == 3) {
      printf("I give up, see you later\n");
      break;
    }
  }
  return 0;
}