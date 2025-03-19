//
// Created by kalle on 18/03/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read_range(int low, int high) {
  int num;
  do {
    printf("Enter a number between %d and %d: ",low,high);
    if (scanf("%d",&num)!=1) {
      while (getchar()!='\n');
      num = low - 1;
    }
    if (num<low || num>high) {
      printf("Invalid input. Please try again.\n");
    }
  } while (num<low || num>high);
  return num;
}
int main() {
  srand(time(NULL));

  printf("Welcome to the dice game. Best of three wins.\n");

  int user_score = 0, program_score = 0;
  for (int round = 1; round <= 3; round++) {
    printf("\nRound %d:\n", round);

    int user_roll = read_range(1, 6);
    printf("You rolled: %d\n", user_roll);

    int program_roll = (user_roll == 6) ? 6 : user_roll + 1;
    printf("The program rolled: %d\n", program_roll);

    if (user_roll > program_roll) {
      user_score++;
      printf("You win this round.\n");
    } else if (user_roll < program_roll) {
      program_score++;
      printf("The program wins this round.\n");
    } else {
      printf("It's a draw.\n");
    }
  }
  printf("\nFinal score - You %d, Program %d\n", user_score, program_score);
  if (user_score > program_score) {
    printf("You win, congratulations.\n");
  } else if (user_score < program_score) {
    printf("The program wins, better luck next time.\n");
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}