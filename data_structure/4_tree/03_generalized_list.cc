#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

typedef struct Node {
  Node *lchild, *rchild;
  int key;
} Node;

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->lchild = p->rchild = nullptr;
  p->key = key;
  return p;
}

void clear(Node *root) {
  if (!root)
    return;
  clear(root->lchild);
  clear(root->rchild);
  free(root);
  return;
}

Node *insert(Node *root, int key) {
  if (!root)
    return getNewNode(key);
  if (rand() % 2)
    root->lchild = insert(root->lchild, key);
  else
    root->rchild = insert(root->rchild, key);
  return root;
}

Node *getTree(int len) {
  Node *root = nullptr;
  for (int i = 0; i < len; i++) {
    root = insert(root, rand() % 10);
  }
  return root;
}

char buff[100] = {'\0'};

int len = 0;

void serialize(Node *root) {
  len += snprintf(buff + len, 100, "%d(", root->key);
  if (root->lchild) {
    serialize(root->lchild);
  }
  if (root->rchild) {
    len += snprintf(buff + len, 100, "%s", ",");
    serialize(root->rchild);
  }
  len += snprintf(buff + len, 100, "%s", ")");
  return;
}

void pre(Node *root) {
  if (!root)
    return;
  cout << root->key << "(" << (root->lchild != nullptr ? root->lchild->key : -1)
       << ',' << (root->rchild != nullptr ? root->rchild->key : -1) << ")"
       << endl;
  pre(root->lchild);
  pre(root->rchild);
  return;
}
void in(Node *root) {
  if (!root)
    return;
  in(root->lchild);
  cout << root->key << " ";
  in(root->rchild);
  return;
}

void post(Node *root) {
  if (!root)
    return;
  post(root->lchild);
  post(root->rchild);
  cout << root->key << " ";
  return;
}

void out() {
  cout << endl;
  for (int i = 0; i < len; i++) {
    cout << buff[i];
  }
  cout << endl;
}

bool isNum(char c) { return c >= '0' && c <= '9'; }

Node *deserialize() {
  Node *root = nullptr;
  stack<Node *> s;
  Node *pre = nullptr;
  bool isRchild = false;
  for (int i = 0; i < len; i++) {
    switch (buff[i]) {
    case '(':
      s.push(pre);
      continue;
    case ')':
      pre = s.top();
      s.pop();
      continue;
    case ',':
      isRchild = true;
      continue;
    default:
      break;
    }
    int j = i + 1;
    for (; isNum(buff[j]); j++)
      ;
    int num = 0;
    for (int k = i; k < j; k++) {
      num = num * 10 + (buff[k] - '0');
    }
    i = j - 1;
    cout << "num: " << num << " " << i << endl;
    pre = getNewNode(num);
    if (!root) {
      root = pre;
      continue;
    }
    if (isRchild) {
      s.top()->rchild = pre;
    } else {
      s.top()->lchild = pre;
    }
    isRchild = false;
  }
  return root;
}

int main() {
  srand(time(0));
  Node *root = getTree(5);
  pre(root);
  cout << endl;
  serialize(root);
  out();
  cout << endl;
  cout << "newRoot" << endl;
  Node *newRoot = deserialize();
  pre(newRoot);
  return 0;
}
