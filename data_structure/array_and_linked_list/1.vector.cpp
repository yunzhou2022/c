#include <ctime>
#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
  int count;
  int size;
  int *data;
} vector;

vector *getNewVector(int n) {
  vector *p = (vector *)malloc(sizeof(vector));
  p->size = n;
  p->count = 0;
  p->data = (int *)malloc(sizeof(int) * n);

  return p;
}

int expand(vector *p) {
  if (p == NULL)
    return 0;
  int *q = (int *)realloc(p->data, sizeof(int) * p->size * 2);
  if (q == NULL)
    return 0;
  p->data = q;
  p->size *= 2;
  return 1;
}

int insert(vector *p, int pos, int val) {
  if (p->size == p->count && !expand(p))
    return 0;
  for (int i = p->count - 1; i >= pos; i--) {
    p->data[i + 1] = p->data[i];
  }
  p->data[pos > p->count ? p->count : pos] = val;
  p->count++;

  return 1;
}

void free(vector *p) {
  if (p == NULL)
    return;
  free(p->data);
  free(p);

  return;
}

int erase(vector *p, int pos) {
  if (pos < 0 || pos >= p->count)
    return -1;
  for (int i = pos; i + 1 < p->count; i++) {
    p->data[i] = p->data[i + 1];
  }

  p->count--;
  return 1;
}

void print(vector *p) {
  int len = 0;
  for (int i = 0; i < p->size; i++) {
    len += printf("%3d", i);
  }
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("-");
  }
  printf("\n");
  for (int i = 0; i < p->count; i++) {
    printf("%3d", p->data[i]);
  }
  printf("\n\n");
}

int main() {
  srand(time(0));
#define MAX_N 20
  vector *p = getNewVector(2);
  for (int i = 0; i < 20; i++) {
    int op = rand() % 4;
    int pos = rand() % (p->count + 2);
    int val = rand() % 100;
    switch (op) {
    case 0:
    case 1:
    case 2:
      printf("at %d insert %d, result is %d\n", pos, val, insert(p, pos, val));
      break;
    case 3:
      printf("erase %d, result is %d\n", pos, erase(p, pos));
      break;
    }
    print(p);
  }

  return 0;
}
