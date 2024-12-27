#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Node {
  int key;
  int h;
  Node *left, *right;
} Node;

Node _NIL;
Node *NIL;
__attribute((constructor)) void init() {
  NIL = &_NIL;
  NIL->h = 0;
  NIL->left = NIL->right = NIL;
  NIL->key = -1;
}

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->h = 1;
  p->key = key;
  p->left = p->right = NIL;
  return p;
}

#define H(root) (root->h)
#define L(root) (root->left)
#define R(root) (root->right)
#define K(root) (root->key)

void update_height(Node *root) {
  H(root) = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
}

Node *left_rotate(Node *root) {
  Node *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  update_height(root);
  update_height(newRoot);
  return newRoot;
}

Node *right_rotate(Node *root) {
  Node *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  update_height(root);
  update_height(newRoot);
  return newRoot;
}

Node *maintain(Node *root) {
  if (abs(H(L(root)) - H(R(root))) < 2)
    return root;
  if (H(L(root)) > H(R(root))) {
    if (H(R(L(root))) > H(L(L(root)))) {
      root->left = left_rotate(root->left);
    }
    root = right_rotate(root);
  } else {
    if (H(L(R(root))) > H(R(R(root)))) {
      root->right = right_rotate(root->right);
    }
    root = left_rotate(root);
  }
  return root;
}

Node *insert(Node *root, int key) {
  if (root == NIL)
    return getNewNode(key);
  if (key < root->key) {
    root->left = insert(root->left, key);
  } else if (key > root->key) {
    root->right = insert(root->right, key);
  } else
    return root;
  update_height(root);
  return maintain(root);
}

Node *remove(Node *root, int key) {
  if (root == NIL)
    return root;
  if (key < root->key) {
    root->left = remove(root->left, key);
  } else if (key > root->key) {
    root->right = remove(root->right, key);
  } else {
    if (L(root) == NIL || R(root) == NIL) {
      Node *tmp = L(root) == NIL ? R(root) : L(root);
      free(root);
      return tmp;
    }
    Node *pre = L(root);
    while (R(pre) != NIL)
      pre = R(pre);
    root->key = pre->key;
    root->left = remove(root->left, pre->key);
  }
  update_height(root);
  return maintain(root);
}

void out(Node *root) {
  if (root == NIL)
    return;
  cout << root->key << " | " << K(L(root)) << " " << K(R(root)) << endl;
  out(L(root));
  out(R(root));
}

int main() {
  int t;
  Node *root = NIL;
  int i=0;
  while (1) {
    cin >> t;
    if (t == -1)
      break;
    root = insert(root, t);
  }
  out(root);

  while (1) {
    cin >> t;
    if (t == -1)
      break;
    root = remove(root, t);
    cout << endl;
    out(root);
  }
  return 0;
}
