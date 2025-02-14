//
// Created by kalle on 24/01/2025.
//

#include <stdio.h>

#define MONTHS 12

int main() {
  float tax_rate, high_tax_rate, income_limit;
  float salaries[MONTHS], taxes[MONTHS];
  float total_income = 0;

  printf("Enter tax rate: ");
  scanf("%f", &tax_rate);
  printf("Enter income limit: ");
  scanf("%f", &income_limit);
  printf("Enter tax rate for income over the limit: ");
  scanf("%f", &high_tax_rate);

  for (int i = 0; i < MONTHS; i++) {
    printf("Enter income for month %d: ", i + 1);
    scanf("%f", &salaries[i]);

    float tax = 0.0;
    float new_total_income = total_income + salaries[i];

    if (total_income < income_limit) {
      if (new_total_income <= income_limit) {
        tax = salaries[i] * (tax_rate / 100);
      } else {
        float low_tax = income_limit - total_income;
        float high_tax = salaries[i] - low_tax;

        tax = (low_tax * (tax_rate / 100)) + (high_tax * (high_tax_rate / 100));
      }
    } else {
      tax = salaries[i] * (high_tax_rate / 100);
    }
    taxes[i] = tax;

    total_income = new_total_income;

    }
    for (int i = 0; i < MONTHS; i++) {
      printf("Month %d: Income = %.2f, Tax = %.2f\n", i + 1, salaries[i], taxes[i]);
  }
  return 0;
}

