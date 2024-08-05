/**
 * @author      : yz
 * @file        : students_table
 * @created     : Saturday Aug 03, 2024 11:11:19 UTC
 */

#include "../include/database.h"

static const char *table_name = "students";
static const char *table_file = "tables/data/student_data.dat";

typedef struct Student {
  char name[20];
  int age;
  int class;
  double height;
} table_data;

static size_t getDataSize(Database *db) { return sizeof(table_data); }

static void printData(void *);
static void init_table(Database *db) {
  db->name = table_name;
  db->table_file = table_file;
  db->table = NULL;
  db->getDataSize = getDataSize;
  db->head = NULL;
  db->printData = printData;
  return;
}
static __attribute__((constructor)) void __register_table() {
  register_table(table_name, init_table);
}

static void printData(void *__data) {
  table_data *data = (table_data *)(__data);
  printf("%15s%3d%3d%5.2lf", data->name, data->age, data->class, data->height);
}
