#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_N 3
#define LCHILD(root, pos) (root->next[pos])
#define RCHILD(root, pos) (root->next[pos + 1])
#define LAST_KEY(root) (root->key[root->n - 1])
#define LAST_CHILD(root) (root->next[root->n])

typedef struct Node {
  int n;
  int key[MAX_N + 1];
  Node *next[MAX_N + 1];
} Node;

Node *getNewNode() {
  Node *p = (Node *)malloc(sizeof(Node));
  p->n = 0;
  memset(p->next, 0, sizeof(Node *) * MAX_N + 1);
  return p;
}

void clear(Node *root) {
  if (!root)
    return;
  for (int i = 0; i <= root->n; i++) {
    clear(root->next[i]);
  }
  free(root);
}

Node *insert_node(Node *root, int key) {
  if (!root) {
    root = getNewNode();
    root->key[(root->n)++] = key;
    return root;
  }
  int pos = 0;
  while (pos < root->n && key > root->key[pos])
    pos++;
  if (root->key[pos] == key)
    return root;
  for (int i = root->n - 1; i >= pos; i--) {
    root->key[i + 1] = root->key[i];
  }
  root->key[pos] = key;
  root->n++;
  return root;
}

Node *insert_maintain(Node *root, Node *child, int pos) {
  if (child->n < MAX_N)
    return root;
  int spos = MAX_N / 2;
  Node *node1 = getNewNode();
  Node *node2 = getNewNode();
  node1->n = spos;
  node2->n = MAX_N - 1 - spos;
  for (int i = 0; i < node1->n; i++) {
    node1->key[i] = child->key[i];
    node1->next[i] = child->next[i];
  }
  node1->next[node1->n] = child->next[node1->n];

  for (int i = 0; i < node2->n; i++) {
    node2->key[i] = child->key[i + spos + 1];
    node2->next[i] = child->next[i + spos + 1];
  }
  node2->next[node2->n] = child->next[child->n];

  for (int i = root->n; i >= pos; i--) {
    root->key[i + 1] = root->key[i];
    root->next[i + 1] = root->next[i];
  }
  root->key[pos] = child->key[spos];
  root->next[pos] = node1;
  root->next[pos + 1] = node2;
  root->n += 1;
  free(child);

  return root;
}

Node *__insert(Node *root, int key) {
  if (!root || root->next[0] == NULL) {
    return insert_node(root, key);
  }
  int pos = 0;
  while (pos < root->n && key > root->key[pos])
    pos++;
  if (root->key[pos] == key)
    return root;
  __insert(root->next[pos], key);
  return insert_maintain(root, root->next[pos], pos);
}

Node *insert(Node *root, int key) {
  root = __insert(root, key);
  if (root->n == MAX_N) {
    Node *p = getNewNode();
    p->next[0] = root;
    root = insert_maintain(p, root, 0);
  }
  return root;
}

void erase_pos(Node *root, int pos) {
  for (int i = pos + 1; i < root->n; i++) {
    root->key[i - 1] = root->key[i];
  }
  root->n--;
  return;
}

void right_rotate(Node *root, int pos) { // pos -> pos+1
  for (int i = RCHILD(root, pos)->n + 1; i > 0; i--) {
    RCHILD(root, pos)->key[i] = RCHILD(root, pos)->key[i - 1];
    RCHILD(root, pos)->next[i] = RCHILD(root, pos)->next[i - 1];
  }
  RCHILD(root, pos)->key[0] = root->key[pos];
  root->key[pos] = LAST_KEY(LCHILD(root, pos));
  RCHILD(root, pos)->next[0] = LAST_CHILD(LCHILD(root, pos));
  LAST_CHILD(LCHILD(root, pos)) = NULL;
  LCHILD(root, pos)->n--;
  RCHILD(root, pos)->n++;
}

void left_rotate(Node *root, int pos) { // pos -> pos+1
  LCHILD(root, pos)->key[LCHILD(root, pos)->n] = root->key[pos];
  LCHILD(root, pos)->n++;
  root->key[pos] = RCHILD(root, pos)->key[0];
  LAST_CHILD(LCHILD(root, pos)) = RCHILD(root, pos)->next[0];
  for (int i = 0; i < RCHILD(root, pos)->n; i++) {
    RCHILD(root, pos)->key[i] = RCHILD(root, pos)->key[i + 1];
    RCHILD(root, pos)->next[i] = RCHILD(root, pos)->next[i + 1];
  }
  LAST_CHILD(RCHILD(root, pos)) = NULL;
  RCHILD(root, pos)->n--;
}

void merge_node(Node *root, int pos) {
  Node *p = getNewNode();
  for (int i = 0; i <= LCHILD(root, pos)->n; i++) {
    p->key[i] = LCHILD(root, pos)->key[i];
    p->next[i] = LCHILD(root, pos)->next[i];
  }
  p->n = LCHILD(root, pos)->n + 1;
  p->key[LCHILD(root, pos)->n] = root->key[pos];
  for (int i = 0; i <= RCHILD(root, pos)->n; i++) {
    p->key[i + p->n] = RCHILD(root, pos)->key[i];
    p->next[i + p->n] = RCHILD(root, pos)->next[i];
  }
  p->n += RCHILD(root, pos)->n;
  free(LCHILD(root, pos));
  free(RCHILD(root, pos));
  for (int i = pos; i < root->n; i++) {
    root->key[i] = root->key[i + 1];
    root->next[i] = root->next[i + 1];
  }
  root->next[pos] = p;
  root->n--;
}

Node *erase_maintain(Node *root, int pos) {
  int lower_bound = (MAX_N + 1) / 2 - 1;
  if (root->next[pos]->n >= lower_bound)
    return root;
  if (pos > 0 && root->next[pos - 1]->n > lower_bound) {
    // 向前借用
    right_rotate(root, pos - 1);
  } else if (pos < root->n && root->next[pos + 1]->n > lower_bound) {
    // 向后借用
    left_rotate(root, pos);
  } else {
    // merge
    if (pos > 0) {
      // pre_merge
      merge_node(root, pos - 1);
    } else {
      merge_node(root, pos);
    }
  }
  return root;
}

Node *__erase(Node *root, int key) {
  if (!root)
    return root;
  int pos = 0;
  while (pos < root->n && root->key[pos] < key)
    pos++;
  if (root->next[0] == NULL) {
    if (root->key[pos] == key)
      erase_pos(root, key);
    return root;
  }
  if (pos < root->n && root->key[pos] == key) {
    Node *pre = root->next[pos];
    while (pre->next[pre->n])
      pre = pre->next[pre->n];
    key = pre->key[pre->n - 1];
    root->key[pos] = key;
  }
  root->next[pos] = __erase(root->next[pos], key);
  return erase_maintain(root, pos);
}

Node *erase(Node *root, int key) {
  root = __erase(root, key);
  if (root->n == 0) {
    Node *newRoot = root->next[0];
    free(root);
    root = newRoot;
  }
  return root;
}

void out(Node *root) {
  if (!root)
    return;
  cout << root->n << " : ";
  for (int i = 0; i < root->n; i++) {
    cout << root->key[i] << " ";
  }
  cout << " | ";
  for (int i = 0; i <= root->n; i++) {
    if (!root->next[i])
      continue;
    cout << root->next[i]->key[0] << " ";
  }
  cout << endl;

  for (int i = 0; i <= root->n; i++) {
    out(root->next[i]);
  }
}

int main() {
  srand(time(0));
#define N 10
  Node *root = NULL;
  for (int i = 0; i < N; i++) {
    int val = rand() % 30;
    cout << "insert " << val << endl;
    root = insert(root, val);
  }
  out(root);
  cout << endl;
  int x;
  while (~scanf("%d", &x)) {
    root = erase(root, x);
    out(root);
  }

  return 0;
}
