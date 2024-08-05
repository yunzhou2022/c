/**
 * @author      : yz
 * @file        : 02_student_system
 * @created     : Friday Aug 02, 2024 05:22:03 UTC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *filename = "student_data.dat";
int scnt;

typedef struct Student {
  char name[20];
  int age;
  int class;
  double height;
  long offset;
} Student;

Student stus[10005];

enum NO_TYPE { LIST = 1, ADD, MODIFY, DELETE, QUIT, ALL_TYPE };

int usage() {
  int no;
  do {
    printf("%d: list student\n", LIST);
    printf("%d: add a student\n", ADD);
    printf("%d: modify a student\n", MODIFY);
    printf("%d: delete a student\n", DELETE);
    printf("%d: exit\n", QUIT);
    printf("mysql > ");
    scanf("%d", &no);
  } while (no < 1 || no > 5);
  return no;
}

void handleList() {
  int len =
      printf("%4s|%10s|%4s|%6s|%7s\n", "id", "name", "age", "class", "height");
  for (int i = 0; i < len; i++)
    printf("=");
  printf("\n");
  for (int i = 0; i < scnt; i++) {
    Student stu = stus[i];
    printf("%4d|%10s|%4d|%6d|%7.2lf|\n", i, stu.name, stu.age, stu.class,
           stu.height);
  }
}
#define format "%10s%4d%4d%7.2lf"
void output_to_file(Student *arr, int n) {
  FILE *fp = fopen(filename, "ab");
  fwrite(arr, sizeof(Student), n, fp);
  //  for (int i = 0; i < n; i++) {
  //    Student stu = arr[i];
  //    fprintf(fp, format "\n", stu.name, stu.age, stu.class, stu.height);
  //  }
  fclose(fp);
}

void clear_file() {
  FILE *fp = fopen(filename, "w");
  fclose(fp);
}

void handleAdd() {
  printf("add new item: (name ,age, class, height)");
  printf("mysql > ");
  scanf("%s%d%d%lf", stus[scnt].name, &stus[scnt].age, &stus[scnt].class,
        &stus[scnt].height);
  output_to_file(stus + scnt, 1);
  scnt++;
}

void restore_students_data(Student *stus, int scnt) {
  clear_file();
  output_to_file(stus, scnt);
}

void modify_data_to_file(Student *stu) {
  FILE *fp = fopen(filename, "rb+");
  fseek(fp, stu->offset, SEEK_SET);
  fwrite(stu, sizeof(Student), 1, fp);
  //  fprintf(fp, format "\n", stu->name, stu->age, stu->class, stu->height);
  fclose(fp);
  return;
}
void handleModify() {
  int id;
  do {
    printf("modify id\n");
    printf("mysql > ");
    scanf("%d", &id);
  } while (id < 0 || id >= scnt);
  printf("intput modified data (name, age, class, height)");
  scanf("%s%d%d%lf", stus[id].name, &stus[id].age, &stus[id].class,
        &stus[id].height);

  modify_data_to_file(stus + id);
  // restore_students_data(stus, scnt);
}

void handleDelete() {
  handleList();
  if (scnt == 0) {
    printf("there is no data\n");
    return;
  }
  int i;
  do {
    printf("input the delete id\n");
    printf("mysql > ");
    scanf("%d", &i);
  } while (i < 0 || i >= scnt);
  fflush(stdin);
  char s[10];
  printf("confirm delete?(y/n) ");
  scanf("%s", s);
  if (s[0] == 'y') {
    for (i = i + 1; i < scnt; i++) {
      long offset = stus[i - 1].offset;
      stus[i - 1] = stus[i];
      stus[i - 1].offset = offset;
    }
    scnt--;
    restore_students_data(stus, scnt);
  }
  printf("handle delete\n");
}

void handleQuit() { exit(0); }

void (*handles[ALL_TYPE])() = {NULL,         handleList,   handleAdd,
                               handleModify, handleDelete, handleQuit};

int init(Student *arr) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("ERROR: file not found %s\n", filename);
    return 0;
  }
  int i = 0;
  while (1) {
    long offset = ftell(fp);
    if (fread(arr + i, sizeof(Student), 1, fp) != 0) {
      arr[i].offset = offset;
      i++;
    } else {
      break;
    }
  }
  // while (fscanf(fp, "%s", arr[i].name) != EOF) {
  //    long offset = ftell(fp);
  //    fscanf(fp, "%d%d%lf", &arr[i].age, &arr[i].class, &arr[i].height);
  //    arr[i].offset = offset;
  //    i++;
  //  }

  fclose(fp);
  return i;
}
int main() {
  scnt = init(stus);

  while (1) {
    int no = usage();
    printf("select no: %d\n", no);
    handles[no]();
    printf("\n\n\n");
  }
  return 0;
}
