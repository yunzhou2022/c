/**
 * @author      : yz
 * @file        : database
 * @created     : Saturday Aug 03, 2024 08:50:13 UTC
 */

#include "../include/database.h"

#include <stdio.h>

struct TableInfo tables[100];

int table_cnt = 0;
Database db;

void register_table(const char *name, InitTable_T init) {
  tables[table_cnt].table_name = name;
  tables[table_cnt].init_table = init;
  table_cnt++;
  return;
}

static enum OP_TYPE choose_table() {
  printf("choose table\n");
  for (int i = 0; i < table_cnt; i++) {
    printf("%d: %s\n", i, tables[i].table_name);
  }
  printf("%d: quit\n", table_cnt);
  int x;
  do {
    printf("input : ");
    scanf("%d", &x);
  } while (x < 0 || x > table_cnt);
  if (x == table_cnt) return OP_END;
  tables[x].init_table(&db);
  return TABLE_USAGE;
}
static enum OP_TYPE table_usage() {
  printf("1: list %stable\n", db.name);
  printf("2: add an item to %s table\n", db.name);
  printf("3: modify an item  of %s  table\n", db.name);
  printf("4: delete an item of %s table\n", db.name);
  printf("5: back\n");

  int x;
  do {
    scanf("%d", &x);

  } while (x < 0 || x > 5);

  switch (x) {
    case 1:
      return LIST_TABLE;
    case 2:
      return ADD_TABLE;
    case 3:
      return MODIFY_TABLE;
    case 4:
      return DELETE_TABLE;
  }
  return CHOOSE_TABLE;
}

static enum OP_TYPE list_table() {
  printf("list %s table\n", db.name);
  return TABLE_USAGE;
}
static enum OP_TYPE add_table() {
  printf("add %s table\n", db.name);
  return TABLE_USAGE;
}
static enum OP_TYPE delete_table() {
  printf("delete %s table\n", db.name);
  return TABLE_USAGE;
}
static enum OP_TYPE modify_table() {
  printf("modify %s table\n", db.name);
  return TABLE_USAGE;
}

static enum OP_TYPE run(enum OP_TYPE status) {
  switch (status) {
    case CHOOSE_TABLE:
      return choose_table();
    case TABLE_USAGE:
      return table_usage();
    case LIST_TABLE:
      return list_table();
    case ADD_TABLE:
      return add_table();
    case MODIFY_TABLE:
      return modify_table();
    case DELETE_TABLE:
      return delete_table();
    default: {
      printf("unknown status: %d\n", status);
    } break;
  }
  return OP_END;
}

void run_database() {
  static enum OP_TYPE status = CHOOSE_TABLE;
  while (1) {
    status = run(status);
    if (status == OP_END) {
      break;
    }
  }
  return;
}

int main() {
  run_database();
  return 0;
}
