#include <cstddef>
#include <iostream>
using namespace std;

typedef struct Node {
  int key;
  Node *left;
  Node *right;
} Node;

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->key = key;
  p->left = p->right = nullptr;
  return p;
}

void clear(Node *root) {
  if (!root)
    return;
  clear(root->left);
  clear(root->right);
  free(root);
}

Node *insert(Node *root, int key) {
  if (!root)
    return getNewNode(key);
  if (key > root->key) {
    root->right = insert(root->right, key);
  } else if (key < root->key) {
    root->left = insert(root->left, key);
  }
  return root;
}

int du(Node *root) {
  int res = 0;
  if (root->left)
    res++;
  if (root->right)
    res++;
  return res;
}

Node *remove(Node *root, int key) {
  if (!root)
    return root;
  if (key < root->key) {
    root->left = remove(root->left, key);
  } else if (key > root->key) {
    root->right = remove(root->right, key);
  } else {
    if (du(root) < 2) {
      Node *tmp = root->left ? root->left : root->right;
      free(root);
      return tmp;
    }
    Node *pre = root->left;
    while (pre->right)
      pre = pre->right;
    root->key = pre->key;
    root->left = remove(root->left, root->key);
  }
  return root;
}

void out(Node *root) {
  if (!root)
    return;
  printf("%d | %d %d\n", root->key, (root->left ? ((root->left)->key) : -1),
         root->right ? root->right->key : -1);
  out(root->left);
  out(root->right);
}

int main() {
  int t;
  Node *root = nullptr;
  while (scanf("%d", &t)) {
    if (t == -1)
      break;
    root = insert(root, t);
  }
  out(root);
  cout << endl;

  while (~scanf("%d", &t)) {
    root = remove(root, t);
    cout << endl;
    out(root);
  }

  return 0;
}
