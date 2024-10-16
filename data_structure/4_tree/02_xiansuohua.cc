#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

typedef struct Node {
  Node *left, *right;
  int key;
  int lflag, rflag;
} Node;

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->left = p->right = nullptr;
  p->key = key;
  p->lflag = p->rflag = 0;
  return p;
}

Node *insert(Node *root, int key) {
  if (!root)
    return getNewNode(key);
  if (rand() % 2)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);
  return root;
}

void clear(Node *root) {
  if (!root)
    return;
  clear(root->left);
  clear(root->right);
  free(root);
  return;
}

void pre_order(Node *root) {
  if (!root)
    return;
  cout << root->key << " ";
  if (!root->lflag)
    pre_order(root->left);
  if (!root->rflag)
    pre_order(root->right);
  return;
}

Node *pre;
Node *head;

void in_order(Node *root) {
  if (!root)
    return;
  if (!root->lflag)
    in_order(root->left);
  if (!head)
    head = root;
  cout << root->key << " ";
  if (root->left == nullptr)
    root->left = pre, root->lflag = 1;
  if (pre && pre->right == nullptr)
    pre->right = root, pre->rflag = 1;
  pre = root;
  if (!root->rflag)
    in_order(root->right);
  return;
}

void post_order(Node *root) {
  if (!root)
    return;
  if (!root->lflag)
    post_order(root->left);
  if (!root->rflag)
    post_order(root->right);
  cout << root->key << " ";
  return;
}

Node *getNext(Node *node) {
  if (!node)
    return nullptr;
  if (node->rflag)
    return node->right;
  node = node->right;
  while (node && node->lflag == 0)
    node = node->left;
  return node;
}

int main() {
  srand(time(0));
  Node *root = nullptr;
#define MAX_N 5
  for (int i = 0; i < MAX_N; ++i) {
    root = insert(root, rand() % 10);
  }

  pre_order(root);
  cout << endl;
  in_order(root);
  cout << endl;
  post_order(root);
  cout << endl;

  Node *node = head;
  while (node != nullptr) {
    cout << node->key << " ";
    node = getNext(node);
  }

  return 0;
}
