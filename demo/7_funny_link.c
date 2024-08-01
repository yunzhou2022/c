/**
 * @author      : yz
 * @file        : 7_funny_link
 * @created     : Thursday Aug 01, 2024 14:47:42 UTC
 */

#include <stdio.h>
#include <stdlib.h>
// #define start(addr, T, d) ((T *)(((void *)addr)-offset(T,d)))
// #define offset(T, d) ((size_t) & ((T *)(0)->d))

#define start(addr, T, d) ((T *)(((void *)addr) - offset(T, d)))
#define offset(T, d) ((size_t)(&(((T *)(0))->d)))

// 1
enum Type { type_A, type_B, type_C,type_D, MAX_TYPE };

typedef struct Link {
  struct Link *next;
  enum Type type;
} Link;

struct A {
  int a;
  Link l;
};
struct B {
  char b;
  Link l;
};
struct C {
  double c;
  Link l;
};

struct D {
  long long  d;
  Link l;
};


// 2

Link *getNewA() {
  struct A *a = (struct A *)malloc(sizeof(struct A));
  a->a = 2;
  a->l.next = NULL;
  a->l.type = type_A;
  return &(a->l);
}
Link *getNewB() {
  struct B *b = (struct B *)malloc(sizeof(struct B));
  b->b = 'b';
  b->l.next = NULL;
  b->l.type = type_B;
  return &(b->l);
}
Link *getNewC() {
  struct C *c = (struct C *)malloc(sizeof(struct C));
  c->c = 2.23;
  c->l.next = NULL;
  c->l.type = type_C;
  return &(c->l);
}


Link *getNewD() {
struct D *d = (struct D *)malloc(sizeof(struct D));
  d->d = 400;
  d->l.next = NULL;
  d->l.type = type_D;
  return &(d->l);
}

// 3

void output_A(Link *p) {
  struct A *a = start(p, struct A, l);
  printf("A: %d\n", a->a);
  return;
}

void output_B(Link *p) {
  struct B *b = start(p, struct B, l);
  printf("B: %c\n", b->b);
  return;
}

void output_C(Link *p) {
  struct C *c = start(p, struct C, l);
  printf("C: %lf\n", c->c);
  return;
}

void output_D(Link *p) {
  struct D *d = start(p, struct D, l);
  printf("D: %lld\n", d->d);
  return;
}

// 4
Link *(*getData[MAX_TYPE])() = {getNewA, getNewB, getNewC, getNewD};
void (*output[MAX_TYPE])(Link *) = {output_A, output_B, output_C, output_D};

int main() {
#define N 10
  Link head, *p = &head;
  for (int i = 0; i < N; i++) {
    p->next = getData[rand() % MAX_TYPE]();
    p = p->next;
  }

  p = head.next;
  while (p) {
    output[p->type](p);
    p = p->next;
  }

  return 0;
}
