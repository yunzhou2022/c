#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
public:
  Node *left, *right;
  int key;
} Node;

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->key = key;
  p->left = nullptr;
  p->right = nullptr;
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

void dfs(Node *root) {
  if (!root)
    return;
  cout << root->key << " ";
  dfs(root->left);
  dfs(root->right);
}

void bfs(Node *root) {
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *cur = q.front();
    q.pop();
    cout << cur->key << " ";
    if (cur->left)
      q.push(cur->left);
    if (cur->right)
      q.push(cur->right);
  }
  return;
}

int main() {
  srand(time(0));
  Node *root = nullptr;
#define MAX_NODE 10
  for (int i = 0; i < 10; i++) {
    root = insert(root, rand() % 100);
  }
  cout << "dfs" << endl;
  dfs(root);
  cout << endl << "bfs" << endl;
  bfs(root);

  return 0;
}
