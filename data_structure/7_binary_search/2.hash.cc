#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
  string s;
  Node *next;
} Node;

typedef struct HashTable {
  int size, cnt;
  Node **data;
} HashTable;

Node *getNewNode(string s) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->s = s;
  p->next = nullptr;
  return p;
}

HashTable *getNewHashTable(int n) {
  HashTable *h = (HashTable *)malloc(sizeof(HashTable));
  h->data = (Node **)malloc(sizeof(Node *) * n);
  for (int i = 0; i < n; i++) {
    h->data[i] = getNewNode("");
  }
  h->size = n;
  h->cnt = 0;
  return h;
}

void clearList(Node *p) {
  Node *q = p;
  while (p) {
    q = p->next;
    free(p);
    p = q;
  }
  return;
}
int getHash(string s) {
  int h = 0;
  int seed = 131;
  for (char c : s) {
    h = h * seed + c;
  }

  return h & 0x7fffffff;
}

void expand(HashTable * p);

void insert(HashTable *h, string s) {
  if(h->cnt >= h->size) expand(h);
  int hash = getHash(s), index = hash % h->size;
  Node *p = getNewNode(s);
  Node *head = h->data[index];
  p->next = head->next;
  head->next = p;
  h->cnt++;
}

void clearHashTable(HashTable *h) {
  for (int i = 0; i < h->size; i++) {
    clearList(h->data[i]);
  }
  free(h->data);
  free(h);
}
void expand(HashTable *h){
  HashTable* new_h = getNewHashTable(h->size *2);
  for(int i=0;i<h->size;i++){
    Node* p = h->data[i]->next;
    while(p){
      insert(new_h, p->s);
      p = p->next;
    }
  }

  swap(h->cnt, new_h->cnt);
  swap(h->size, new_h->size);
  swap(h->data, new_h->data);
}


bool find(HashTable *h, string s) {
  int hash = getHash(s), index = hash % h->size;
  Node *q = h->data[index]->next;

  while (q) {
    if (q->s == s)
      return true;
    q = q->next;
  }

  return false;
}

void out(HashTable *h) {
  cout << endl << "cout: " << h->cnt << "  size: " << h->size << endl;
  for (int i = 0; i < h->size; i++) {
    Node *head = h->data[i]->next;
    while (head) {
      cout << head->s << "->";
      head = head->next;
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  string s;
#define MAX_N 2
  HashTable *h = getNewHashTable(MAX_N);
  while (1) {
    cin >> s;
    if (s == "end")
      break;
    insert(h, s);
    out(h);
  }
  while (1) {
    cin >> s;
    if (cin.eof())
      break;
    bool res = find(h, s);
    cout << res << endl;
  }

  clearHashTable(h);
  return 0;
}