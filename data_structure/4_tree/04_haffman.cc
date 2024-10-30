#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;

typedef struct Node {
  Node *lchild, *rchild;
  int freq;
  char ch;
} Node;

Node *getNewNode(int freq, char ch) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->ch = ch;
  p->freq = freq;
  p->lchild = p->rchild = nullptr;
  return p;
}

void clear(Node *root) {
  if (!root)
    return;
  clear(root->lchild);
  clear(root->rchild);
  return;
}

void swap_node(Node **node_arr, int i, int j) {
  Node *temp = node_arr[i];
  node_arr[i] = node_arr[j];
  node_arr[j] = temp;
  return;
}

int findMinNode(Node **node_arr, int last) {
  int ind = 0;
  for (int j = 0; j <= last; j++) {
    if (node_arr[j]->freq < node_arr[ind]->freq) {
      ind = j;
    }
  }
  return ind;
}

Node *buildHaffmanTree(Node **node_arr, int n) {
  for (int i = 1; i < n; i++) {
    // find two node;
    swap_node(node_arr, findMinNode(node_arr, n - i), n - i);
    swap_node(node_arr, findMinNode(node_arr, n - i - 1), n - i - 1);
    // merge two node;
    int freq = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;
    Node *node = getNewNode(freq, 0);
    node->lchild = node_arr[n - i];
    node->rchild = node_arr[n - i - 1];
    node_arr[n - i - 1] = node;
  }
  return node_arr[0];
}

void extractHaffmanCode(Node *root, char *buff, int len) {
  if (!root)
    return;
  if (!root->lchild && !root->rchild && root->ch != 0) {
    cout << root->ch << ": " << static_cast<string>(buff);
    //    for (int i = 0; i < len; i++) {
    //     cout << buff[i];
    //  }
    cout << endl;
  }
  buff[len] = '0';
  extractHaffmanCode(root->lchild, buff, len + 1);
  buff[len] = '1';
  extractHaffmanCode(root->rchild, buff, len + 1);
  return;
}
int main() {
  int n, freq;
  char ch[10];
  cin >> n;
  Node **node_arr = (Node **)malloc(sizeof(Node *));
  for (int i = 0; i < n; i++) {
    cin >> ch >> freq;
    node_arr[i] = getNewNode(freq, ch[0]);
  }
  Node *root = buildHaffmanTree(node_arr, n);
  char buff[1000];
  extractHaffmanCode(root, buff, 0);
  clear(root);
  return 0;
}
