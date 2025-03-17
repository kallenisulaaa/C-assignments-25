//
// Created by kalle on 18/03/2025.
//

#include <stdio.h>

int main(){
    int num_students, student_num, grade;

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    int grades[num_students];
    for (int i = 0; i < num_students; i++) {
      grades[i] = -1;
    }

    printf("Enter student number and grade (-1 to 5). Enter 0 to stop.\n");

    while (1) {
    printf("Student number (1-%d): ", num_students);
    scanf("%d", &student_num);

    if (student_num == 0) {
      break;
    }

    if (student_num < 1 || student_num > num_students) {
      printf("Invalid input. Please try again.\n");
      continue;
    }
    printf("Enter grade (-1 for N/A, 0-5): ");
    scanf("%d", &grade);
    if (grade < -1 || grade > 5) {
      printf("Invalid input. Please try again.\n");
    } else {
      grades[student_num - 1] = grade;
    }

    }
  printf("\nStudent grades:\n");
  for (int i = 0; i < num_students; i++) {
    if (grades[i] == -1) {
      printf("Student %d: N/A\n", i + 1);
    } else {
      printf("Student %d: %d\n", i + 1, grades[i]);
    }
  }

  return 0;
}

