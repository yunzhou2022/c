#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define father(i) ((i) / 2)
#define cmp <
#define lchild(i) ((i) * 2)
#define rchild(i) ((i) * 2 + 1)
#define swap(a, b)                                                             \
  ({                                                                           \
    __typeof(a) __c = (a);                                                     \
    (a) = (b);                                                                 \
    (b) = __c;                                                                 \
  })

typedef struct PriorityQueue {
  int *_data, *data;
  int size, n;
} PriorityQueue;

PriorityQueue *pq;

void init(int size) {
  pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  pq->_data = (int *)malloc(sizeof(int) * size);
  pq->data = pq->_data - 1;
  pq->size = size;
  pq->n = 0;

  return;
}

void clear(PriorityQueue *pq) {
  if (!pq)
    return;
  free(pq->_data);
  free(pq);
  return;
}

bool isFull(PriorityQueue *pq) { return pq->n == pq->size; }

bool isEmpty(PriorityQueue *pq) { return pq->n == 0; }

void up_update(int *data, int n) {
  int i = n;
  while (i != 1 && data[i] cmp data[father(i)]) {
    swap(data[i], data[father(i)]);
    i = father(i);
  }
}

void down_update(int *data, int n) {
  int i = 1;
  while (i != n) {
    int left = data[lchild(i)];
    int right = data[rchild(i)];
    if (left cmp right) {
      if (left cmp data[i]) {
        swap(data[lchild(i)], data[i]);
        i = lchild(i);
      }
    } else {
      if (right cmp data[i]) {
        swap(data[rchild(i)], data[i]);
        i = rchild(i);
      } else {
        return;
      }
    }
  }
  return;
}

void down_update_v2(int *data, int n) {
  int i = 1;
  while (lchild(i) < n) {
    int ind = i, l = lchild(i), r = rchild(i);
    if (data[l] cmp data[ind])
      ind = l;
    if (r < n && data[r] cmp data[ind])
      ind = r;
    if (ind == i)
      break;
    swap(data[ind], data[i]);
    i = ind;
  }
  return;
}

bool push(PriorityQueue *pq, int val) {
  if (isFull(pq))
    return false;
  pq->n++;
  pq->data[pq->n] = val;
  up_update(pq->data, pq->n);
  return true;
}

bool pop(PriorityQueue *pq) {
  if (isEmpty(pq))
    return false;
  swap(pq->data[1], pq->data[pq->n]);
  pq->n--;
  // down_update(pq->data, pq->n);
  down_update_v2(pq->data, pq->n);
  return true;
}

void out() {
  for (int i = 1; i <= pq->n; i++) {
    cout << pq->data[i] << " ";
  }
  cout << endl;
}

int main() {
  init(10);
  int op, num;
  while (scanf("%d%d", &op, &num) != EOF) {
    if (op == 1) {
      push(pq, num);
    } else {
      pop(pq);
    }
    out();
  }
  return 0;
}
