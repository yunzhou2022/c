/**
 * @author      : yz
 * @file        : 02_student_system
 * @created     : Friday Aug 02, 2024 05:22:03 UTC
 */

#include <stdio.h>
#include <stdlib.h>

int usage() {
  int no;
  do {
    printf("1: list student\n");
    printf("2: student\n");
    printf("3: modify a student\n");
    printf("4: delete a student\n");
    printf("5: exit\n");
    printf("mysql > ");
    scanf("%d", &no);
  } while (no < 1 || no > 5);
  return no;
}

int main() {
  while (1) {
    int no = usage();
    switch (no) {
    case 1:
      printf("list student\n");
      break;
    case 2:
      printf("student\n");
      break;
    case 3:
      printf("modify a student\n");
      break;
    case 4:
      printf("delete a student");
      break;
    case 5:
      exit(0);
      break;
    default:
      break;
    }
  }
  return 0;
}
