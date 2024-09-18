#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef struct Node {
  Node *next;
  int val;
} Node;

Node *getNewNode(int val) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->next = NULL;
  p->val = val;

  return p;
}

Node *insert(Node *head, int pos, int val) {
  Node vhead, *p = &vhead;
  vhead.next = head;
  for (int i = 0; i < pos; i++) {
    p = p->next;
  }
  Node *q = getNewNode(val);
  q->next = p->next;
  p->next = q;

  return vhead.next;
}
// Node *insert(Node *head, int pos, int val) {
//   if (pos == 0) {
//     Node *p = getNewNode(val);
//     p->next = head;
//     return p;
//   }
//
//   Node *p = head;
//   for (int i = 1; i < pos; i++) {
//     p = p->next;
//   }
//   Node *q = getNewNode(val);
//   q->next = p->next;
//   p->next = q;
//
//   return head;
// }
//
void free(Node *head) {
  if (head == NULL)
    return;

  for (Node *p = head, *q; p; p = q) {
    q = p->next;
    free(p);
  }
  return;
}

void print(Node *head) {
  int len = 0;
  for (Node *p = head; p; p = p->next) {
    len++;
  }

  for (int i = 0; i < len; i++) {
    printf("%3d", i);
    printf("  ");
  }
  printf("\n");
  for (Node *p = head; p; p = p->next) {
    printf("%3d", p->val);
    printf("->");
  }

  printf("\n");
  return;
}

int search(Node *head, int val) {
  int pos = -1;
  for (Node *p = head; p; p = p->next) {
    pos++;
    if (p->val == val) {
      break;
    }
  }

  if (pos != -1) {
    printf("find %d at %d\n", val, pos);
    print(head);
    int len = 5 * pos + 2;
    for (int i = 0; i < len; i++)
      printf(" ");
    printf("^\n");
    for (int i = 0; i < len; i++)
      printf(" ");
    printf("|\n");
  }
  return pos;
}
int main() {
  srand(time(0));
#define MAX_OP 7
  Node *head = NULL;
  for (int i = 0; i < MAX_OP; i++) {
    int pos = rand() % (i + 1), val = rand() % 100;
    printf("insert %d at %d\n", val, pos);
    head = insert(head, pos, val);
    print(head);
  }

  int target;
  while (scanf("%d", &target) != EOF) {
    search(head, target);
  }

  return 0;
}
