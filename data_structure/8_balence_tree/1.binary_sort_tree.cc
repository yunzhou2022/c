#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

typedef struct Node {
  int key;
  Node *left, *right;
} Node;

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->key = key;
  p->left = p->right = nullptr;
  return p;
}

Node *insert(Node *root, int key) {
  if (!root)
    return getNewNode(key);
  if (key == root->key)
    return root;
  if (key < root->key)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);
  return root;
}

Node *pre(Node *root) {
  Node *tmp = root->left;
  while (tmp->right)
    tmp = tmp->right;
  return tmp;
}

Node *remove(Node *root, int key) {
  if (!root)
    return root;
  if (key < root->key) {
    root->left = remove(root->left, key);
  } else if (key > root->key) {
    root->right = remove(root->right, key);
  } else {
    if (!root->left && !root->right)
      return nullptr;
    if (!root->left || !root->right) {
      Node *tmp = root->left ? root->left : root->right;
      free(root);
      return tmp;
    }

    Node *tmp = pre(root);
    root->key = tmp->key;
    root->left = remove(root->left, tmp->key);
  }
  return root;
}

void preOut(Node *root) {
  if (!root)
    return;
  preOut(root->left);
  cout << root->key << "->";
  preOut(root->right);
}

void outTree(Node *root) {
  if (!root)
    return;
  printf("%d(%d,%d)\n", root->key, root->left ? root->left->key : -1,
         root->right ? root->right->key : -1);
  outTree(root->left);
  outTree(root->right);
}

int main() {
  srand(time(0));
#define N 10
  Node *root = nullptr;
  for (int i = 0; i < N; i++) {
    int key = random() % 20;
    root = insert(root, key);
    cout << "insert " << key << endl;
  }
  outTree(root);
  preOut(root);

  cout << endl;
  while (1) {
    int key;
    cin >> key;
    if (cin.eof())
      break;
    root = remove(root, key);
    preOut(root);
    cout << endl;
  }

  return 0;
}
