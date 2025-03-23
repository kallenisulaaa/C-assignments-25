//
// Created by kalle on 23/03/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBJECT_NAME_LENGTH 50
#define REPORT_FILENAME "Student_report.txt"

#define GRADE_5 90
#define GRADE_4 80
#define GRADE_3 70
#define GRADE_2 60
#define GRADE_1 50

int calculateGrade(float score) {
  if (score >= GRADE_5) return 5;
  else if (score >= GRADE_4) return 4;
  else if (score >= GRADE_3) return 3;
  else if (score >= GRADE_2) return 2;
  else if (score >= GRADE_1) return 1;
  else return 0;
}

int main() {
  char studentname[MAX_NAME_LENGTH];
  int numsubjects;

  printf("Student grade calculator\n");

  printf("Enter your name: \n");
  fgets(studentname, sizeof(studentname), stdin);
  studentname[strcspn(studentname, "\n")] = 0;

  printf("How many subjects do you want to calculate grades for? ");
  scanf("%d", &numsubjects);

  char subjects[numsubjects][MAX_SUBJECT_NAME_LENGTH];
  float scores[numsubjects];
  int grades[numsubjects];
  float totalscore = 0.0;
  for (int i = 0; i < numsubjects; i++) {
    printf("Enter subject number %d: \n", i + 1);
    scanf(" %[^\n]s", subjects[i]);
    printf("Enter your score for %s (0-100): ", subjects[i]);
    scanf("%f", &scores[i]);
    grades[i] = calculateGrade(scores[i]);
    totalscore += scores[i];
  }

  float averagescore = totalscore / numsubjects;
  float averagegrade = 0.0;
  for (int i = 0; i < numsubjects; i++) {
    averagegrade += scores[i];
  }
  averagegrade /= numsubjects;

  printf("\n----------------------------------------------------\n");
  printf("Student: %s \n", studentname);
  printf("\n----------------------------------------------------\n");
  printf("Subject                    Score          Grade\n");
  printf("------------------------------------------------------\n");
  for (int i = 0; i < numsubjects; i++) {
    printf("%-25s %-14.2f %-5d\n", subjects[i], scores[i], grades[i]);
  }
  printf("------------------------------------------------------\n");
  printf("Average score: %.2f\n", averagescore);
  printf("Average grade: %.2f\n", averagegrade);
  printf("------------------------------------------------------\n");

  FILE *file = fopen(REPORT_FILENAME, "w");
  if (file == NULL) {
    printf("Could not write to file.\n");
  } else {
    fprintf(file, "------------------------------------------------------\n");
    fprintf(file, "Student: %s \n", studentname);
    fprintf(file, "------------------------------------------------------\n");
    fprintf(file, "Subject                    Score          Grade\n");
    fprintf(file, "------------------------------------------------------\n");
    for (int i = 0; i < numsubjects; i++) {
      fprintf(file, "%-25s %-14.2f %-5d\n", subjects[i], scores[i], grades[i]);
    }
    fprintf(file, "------------------------------------------------------\n");
    fprintf(file, "Average score: %.2f\n", averagescore);
    fprintf(file, "Average grade: %.2f\n", averagegrade);
    fprintf(file, "------------------------------------------------------\n");
    fclose(file);
    printf("The report has been saved to %s\n", REPORT_FILENAME);
  }
  return 0;
}
