#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_N 3

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

  return 0;
}
