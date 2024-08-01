/**
 * @author      : yz
 * @file        : 5_node
 * @created     : Thursday Aug 01, 2024 13:30:32 UTC
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

Node *getNewNode(int val) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->val = val;
  p->next = NULL;
  return p;
}

Node *InsertNode(Node *head, int pos, int val) {
  Node *node = getNewNode(val);
  if (pos == 0) {
    return node;
  }

  Node *q = head;
  for (int i = 0; i < pos - 1; i++) {
    q = q->next;
  }
  Node *next = q->next;
  q->next = node;
  node->next = next;
  return head;
}

void clear(Node *head) {
  Node *p = head;
  while (p) {
    Node *next = p->next;
    free(p);
    p = next;
  }
}

void print(Node *head) {
  int n = 0;
  Node *p = head;
  while (p) {
    p = p->next;
    n++;
  }
  for (int i = 0; i < n; i++) {
    printf("%3d ", i);
  }
  printf("\n");
  p = head;
  while (p) {
    printf("%3d ", p->val);
    p = p->next;
  }
  printf("\n\n\n");
}

int main() {
  srand(time(0));
#define N 7
  int pos, val;
  Node *head;
  for (int i = 0; i < N; i++) {
    pos = rand() % (i+1);
    val = rand() % 100;
    head = InsertNode(head, pos, val);
    print(head);
  }

  return 0;
}
