/**
 * @author      : yz
 * @file        : database
 * @created     : Saturday Aug 03, 2024 08:50:13 UTC
 */

#include "../include/database.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TableInfo tables[100];

int table_cnt = 0;
Database db;

void register_table(const char *name, InitTable_T init) {
  tables[table_cnt].table_name = name;
  tables[table_cnt].init_table = init;
  table_cnt++;
  return;
}

static struct table_data *getNewTableData(char *data, long offset) {
  struct table_data *p = (struct table_data *)malloc(sizeof(struct table_data));

  p->data = malloc(db.getDataSize());
  memcpy(p->data, data, db.getDataSize()), p->offset = offset;
  p->next = NULL;
  return p;
}

static int load_table_data() {
  char buff[db.getDataSize()];
  struct table_data *p = db.head;
  int data_cnt = 0;
  while (1) {
    long offset = ftell(db.table);
    if (fread(buff, db.getDataSize(), 1, db.table) == 0) break;
    p->next = getNewTableData(buff, offset);
    p = p->next;
    data_cnt++;
  }

  printf("load data success: %d items\n", data_cnt);
  return data_cnt;
}

static void clear_table() {
  struct table_data *p = db.head->next, *q;
  while (p) {
    q = p->next;
    free(p->data);
    free(p);
    p = q;
  }
  return;
}

static void close_table() {
  clear_table();
  if (db.table == NULL) return;
  fclose(db.table);
  return;
}

static void open_table() {
  db.table = fopen(db.table_file, "rb+");
  if (db.table == NULL) {
    printf("can't open file :%s\n", db.table_file);
    exit(1);
  }

  load_table_data();
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
  close_table();
  tables[x].init_table(&db);
  open_table();
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
  struct table_data *p = db.head->next;
  while (p) {
    db.printData(p->data);
    p = p->next;
  }
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
