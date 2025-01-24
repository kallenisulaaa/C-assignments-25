//
// Created by kalle on 24/01/2025.
//

#include <cstdio>

int main() {
  float bussi, taksi, raha;
  int valinta;

  printf("How much is a bus ticket? \n");
  scanf("%f", &bussi);

  printf("How much is a taxi ride? \n");
  scanf("%f", &taksi);

  printf("How much money do you have? \n");
  scanf("%f", &raha);

  while (1) {
    if (raha < bussi && raha < taksi) {
      printf("You're out of money, time to walk. Bye! \n");
      break;
    }
    printf("Your balance is %.2f euros. \n", raha);
    printf("Do you want to take the: \n");
    printf("1: Bus (%.2f euros)\n", bussi);
    printf("2: Taxi (%.2f euros)\n", taksi);
    printf("Select: ");
    scanf("%d", &valinta);

    if (valinta == 1) {
      if (raha >= bussi) {
        raha -= bussi;;
        printf("You took the bus. Your balance is %.2f euros. \n", raha);
      } else {
          printf("You do not have money for a bus ticket. \n");
      }
    } else if (valinta == 2) {
      if (raha >= taksi) {
        raha -= taksi;
        printf("You went by taxi. Your balance is %.2f euros. \n", raha);
        } else {
          printf("You do not have money for a taxi. \n");
        }
      } else {
        printf("Choose either the bus or the taxi. \n");
      }
    }

    return 0;
}