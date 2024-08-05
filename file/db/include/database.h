/**
 * @author      : yunzhou (yunzhou@$HOSTNAME)
 * @file        : database
 * @created     : Saturday Aug 03, 2024 08:47:50 UTC
 */

#ifndef DATABASE_H

#define DATABASE_H
#include <stdio.h>

enum OP_TYPE {
  CHOOSE_TABLE,
  TABLE_USAGE,
  OP_END,
  LIST_TABLE,
  ADD_TABLE,
  MODIFY_TABLE,
  DELETE_TABLE
};
;

struct table_data {
  void *data;
  long offset;
  struct table_data *next;
};

typedef struct Database {
  const char *name;
  FILE *table;
  const char *table_file;
  struct table_data *head;
  size_t (*getDataSize)();
  void(*printData)(void *);
} Database;

typedef void (*InitTable_T)(struct Database *);

typedef struct TableInfo {
  const char *table_name;
  InitTable_T init_table;
} TableInfo;

void run_database();

void register_table(const char *, InitTable_T);

#endif /* end of include guard DATABASE_H */
