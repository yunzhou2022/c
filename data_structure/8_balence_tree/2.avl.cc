#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Node {
  int key;
  Node *left, *right;
  int h;
} Node;

Node __NIL;
Node *NIL;

__attribute((constructor)) void initNIL() {
  NIL = &__NIL;
  NIL->h = 0;
  NIL->left = NIL->right = NIL;
  NIL->key = -1;
}

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->h = 1;
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

#define L(R) (R->left)
#define R(R) (R->right)
#define K(R) (R->key)
#define H(R) (R->h)

void updateHeight(Node *root) {
  int newHeight = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
  root->h = newHeight;
}

Node *left_rotate(Node *root) {
  Node *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  updateHeight(root);
  updateHeight(newRoot);
  return newRoot;
}

Node *right_rotate(Node *root) {
  Node *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  updateHeight(root);
  updateHeight(newRoot);
  return newRoot;
}

Node *maintain(Node *root) {
  if (abs(H(L(root)) - H(R(root))) < 2) {
    return root;
  }
  if (H(L(root)) > H(R(root))) {
    // L;
    if (H(L(L(root))) < H(R(L(root)))) {
      // LR;
      root->left = left_rotate(L(root));
    }
    root = right_rotate(root);
  } else {
    // R
    if (H(R(R(root))) < H(L(R(root)))) {
      // RL
      root->right = right_rotate(root->right);
    }
    root = left_rotate(root);
  }

  return root;
}

Node *insert(Node *root, int key) {
  if (root == NIL)
    return getNewNode(key);
  if (key < root->key)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);
  updateHeight(root);
  return maintain(root);
}

Node *pre(Node *root) {
  Node *tmp = root->left;
  while (tmp->right != NIL)
    tmp = tmp->right;
  return tmp;
}

Node *remove(Node *root, int key) {
  if (root == NIL)
    return root;
  if (key < root->key)
    root->left = remove(root->left, key);
  else if (key > root->key)
    root->right = remove(root->right, key);
  else {
    if (root->left == NIL || root->right == NIL) {
      Node *tmp = root->left == NIL ? root->right : root->left;
      free(root);
      return tmp;
    } else {
      Node *tmp = pre(root);
      root->key = tmp->key;
      root->left = remove(root->left, tmp->key);
    }
  }
  updateHeight(root);
  return maintain(root);
}

void out(Node *root) {
  if (root == NIL) {
    return;
  }

  printf("%d[%d, %d]\n", K(root), K(L(root)), K(R(root)));
  out(L(root));
  out(R(root));
}

int main() {
  Node *root = NIL;
  int t;
  while (1) {
    cin >> t;
    if (t == -1) {
      break;
    }
    root = insert(root, t);
  }
  out(root);
  cout << endl;
  cout << endl;
  root = remove(root, 5);
  root = remove(root, 6);
  out(root);
  clear(root);
  return 0;
}
