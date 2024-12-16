#include <iostream>
using namespace std;

#define RED 0
#define BLACK 1

typedef struct Node {
  int key;
  Node *left, *right;
  int color;
} Node;

Node tmp;
Node *NIL;
__attribute__((constructor)) void __init() {
  NIL = &tmp;
  NIL->color = BLACK;
  NIL->left = NIL->right = NIL;
  NIL->key = -1;
}

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->color = RED;
  p->left = p->right = NIL;
  p->key = key;
  return p;
}

void clear(Node *root) {
  if (root == NIL)
    return;
  clear(root->left);
  clear(root->right);
  free(root);
}

#define K(n) (n->key)
#define C(n) (n->color)
#define L(n) (n->left)
#define R(n) (n->right)

bool child_has_red(Node *n) { return C(L(n)) == RED || C(R(n)) == RED; }

Node *left_rotate(Node *root) {
  Node *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  return newRoot;
}

Node *right_rotate(Node *root) {
  Node *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  return newRoot;
}

Node *insert_update(Node *root) {
  if (!child_has_red(root))
    return root;
  int flag = 0;
  if (C(L(root)) == RED && child_has_red(L(root)))
    flag = 1;
  if (C(R(root)) == RED && child_has_red(R(root)))
    flag = 2;
  if (flag == 0)
    return root;
  if (flag == 1) {
    if (C(R(root)) == RED) {
      C(root) = RED;
      C(L(root)) = BLACK;
      C(R(root)) = BLACK;
      return root;
    }
    if (C(R(L(root))) == RED) {
      root->left = left_rotate(root->left);
    }
    root = right_rotate(root);
  } else {
    if (C(L(root)) == RED) {
      C(root) = RED;
      C(R(root)) = BLACK;
      C(L(root)) = BLACK;
      return root;
    }
    if (C(L(R(root))) == RED) {
      root->right = right_rotate(root->right);
    }
    root = left_rotate(root);
  }
  C(root) = RED;
  C(L(root)) = BLACK;
  C(R(root)) = BLACK;
  return root;
}

Node *__insert(Node *root, int key) {
  if (root == NIL)
    return getNewNode(key);
  if (key < root->key) {
    root->left = __insert(root->left, key);
  } else {
    root->right = __insert(root->right, key);
  }
  return insert_update(root);
}

Node *insert(Node *root, int key) {
  root = __insert(root, key);
  root->color = BLACK;
  return root;
}

void out(Node *root) {
  if (root == NIL) {
    return;
  }
  printf("%d[%d, %d, %d]\n", K(root), C(root), K(L(root)), K(R(root)));
  out(root->left);
  out(root->right);
}

int main() {
  int k;
  Node *root = NIL;
  while (1) {
    cin >> k;
    if (k == -1)
      break;
    root = insert(root, k);
  }
  out(root);

  return 0;
}
