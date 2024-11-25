#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;

#define father(i) ((i) / 2)
#define lchild(i) ((i) * 2)
#define rchild(i) ((i) * 2 + 1)
#define swap(a, b)                                                             \
  {                                                                            \
    __typeof(a) __c = a;                                                       \
    a = b;                                                                     \
    b = __c;                                                                   \
  }

typedef struct Node {
  Node *lchild, *rchild;
  int freq;
  char ch;
} Node;

typedef struct Heap {
  Node **__data, **data;
  int size, n;
} Heap;

void initHeap(Heap *h, int size) {
  h->__data = (Node **)(malloc(sizeof(Node *) * size));
  h->data = h->__data - 1;
  h->size = size;
  h->n = 0;
  return;
}

Node *heapTop(Heap *h) { return h->data[1]; }

int cmp(Node **data, int i, int j) { return data[i]->freq < data[j]->freq; }

void up_update(Node **data, int n) {
  int i = n;
  while (i > 1 && cmp(data, i, father(i))) {
    swap(data[father(i)], data[i]);
    i = father(i);
  }
  return;
}

void down_update(Node **data, int i, int n) {
  while (lchild(i) <= n) {
    int ind = i;
    if (cmp(data, lchild(ind), ind))
      ind = lchild(ind);
    if (rchild(ind) <= n && cmp(data, rchild(ind), ind))
      ind = rchild(ind);
    if (ind == i)
      break;
    swap(data[ind], data[i]);
    i = ind;
  }
  return;
}
bool heapIsFull(Heap *h) { return h->n == h->size; }
bool headpIsEmpty(Heap *h) { return h->n == 0; }
int pushHeap(Heap *h, Node *v) {
  if (heapIsFull(h))
    return -1;
  h->n++;
  h->data[h->n] = v;
  up_update(h->data, h->n);
  return 1;
}
int popHead(Heap *h) {
  if (headpIsEmpty(h))
    return -1;
  //  swap(h->data[h->n], h->data[1]);
  h->data[1] = h->data[h->n];
  h->n--;
  down_update(h->data, 1, h->n);
  return 1;
}

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
  Heap *h = (Heap *)malloc(sizeof(Heap));
  initHeap(h, n);
  for (int i = 0; i < n; i++) {
    pushHeap(h, node_arr[i]);
  }
  for (int i = 1; i < n; i++) {
    // find two node;
    // swap_node(node_arr, findMinNode(node_arr, n - i), n - i);
    // swap_node(node_arr, findMinNode(node_arr, n - i - 1), n - i - 1);
    Node *min = heapTop(h);
    popHead(h);
    Node *min2 = heapTop(h);
    popHead(h);
    Node *node3 = getNewNode(min->freq + min2->freq, 0);
    node3->lchild = min;
    node3->rchild = min2;
    pushHeap(h, node3);
    // merge two node;
    //    int freq = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;
    //   Node *node = getNewNode(freq, 0);
    //  node->lchild = node_arr[n - i];
    // node->rchild = node_arr[n - i - 1];
    // node_arr[n - i - 1] = node;
  }
  return heapTop(h);
  //  return node_arr[0];
}

void extractHaffmanCode(Node *root, char *buff, int len) {
  if (!root)
    return;
  if (!root->lchild && !root->rchild && root->ch != 0) {
    cout << root->ch << ": " << static_cast<string>(buff);
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
  char buff[1000] = {0};
  extractHaffmanCode(root, buff, 0);
  clear(root);
  return 0;
}
