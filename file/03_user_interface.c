/**
 * @author      : yz
 * @file        : 03_user_interface
 * @created     : Saturday Aug 03, 2024 03:34:56 UTC
 */

#include <stdio.h>

int page1() {
  printf("into page1\n");
  printf("1: into page2\n");
  printf("2: into page3\n");
  printf("3: into page4\n");
  printf("4: into page5\n");
  int cmd;
  do {
    printf("input > ");
    scanf("%d", &cmd);
  } while (cmd < 1 || cmd > 4);

  return cmd+1;
}

int page2() {
  printf("into page2\n");
  printf("1: into page5\n");
  printf("0: into page1\n");
  int cmd;
  do {
    printf("input > ");
    scanf("%d", &cmd);
  } while (cmd < 0 || cmd > 1);

  return cmd?5:1;
}

int page3() {
  printf("into page3\n");
  return 5;
}

int page4() {
  printf("into page4\n");
  printf("1: into page5\n");
  printf("0: into page1\n");
  int cmd;
  do {
    printf("input > ");
    scanf("%d", &cmd);
  } while (cmd < 0 || cmd > 1);

  return cmd?5:1;
}

int page5() {
  printf("into page5\n");
  return 1;
}

int main() {
  int status = 1;
  while (1) {
    switch (status) {
    case 1: {
      int x = page1();
      status = x;
    } break;
    case 2: {
      int x = page2();
      status = x;
    } break;
    case 3: {
      int x = page3();
      status = x;
    } break;
    case 4: {
      int x = page4();
      status = x;
    } break;
    case 5: {
      int x = page5();
      status = x;
    } break;
    default : break;
    }
  }

  return 0;
}
