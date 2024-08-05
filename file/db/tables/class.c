/**
 * @author      : yz
 * @file        : students_table
 * @created     : Saturday Aug 03, 2024 11:11:19 UTC
 */

#include "../include/database.h"

static const char *table_name = "class";

static void init_table(Database *db) {
  db->name = table_name;
  return;
}

static __attribute__((constructor)) void __register_table() {
  register_table(table_name, init_table);
}
