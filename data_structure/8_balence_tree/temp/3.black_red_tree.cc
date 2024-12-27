#include <iostream>
using namespace std;

typedef struct Node {
  int color;
  int key;
  Node *left, *right;
} Node;

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

Node __NIL;
Node *NIL;

__attribute((constructor)) void init() {
  NIL = &__NIL;
  NIL->color = BLACK;
  NIL->left = NIL->right = NIL;
  NIL->key = -1;
}

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->color = RED;
  p->key = key;
  p->left = p->right = NIL;
  return p;
}

void clear(Node *root) {
  if (root == NIL)
    return;
  clear(root->left);
  clear(root->right);
  free(root);
  return;
}

#define C(n) (n->color)
#define K(n) (n->key)
#define L(n) (n->left)
#define R(n) (n->right)

bool hasRed(Node *root) { return C(L(root)) == RED || C(R(root)) == RED; }

Node *right_rotate(Node *root) {
  Node *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  return newRoot;
}

Node *left_rotate(Node *root) {
  Node *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  return newRoot;
}

Node *insert_maintain(Node *root) {
  if (root == NIL || !hasRed(root))
    return root;
  if (C(L(root)) == RED && C(R(root)) == RED &&
      (hasRed(L(root)) || hasRed(R(root)))) {
    root->color = RED;
    C(L(root)) = C(R(root)) = BLACK;
    return root;
  }
  if ((C(L(root)) == RED && !hasRed(L(root))) ||
      (C(R(root)) == RED && !hasRed(R(root))))
    return root;
  if (C(L(root)) == RED) {
    if (C(R(L(root))) == RED) {
      // LR
      root->left = left_rotate(root->left);
    }
    root = right_rotate(root);
  } else {
    if (C(L(R(root))) == RED) {
      root->right = right_rotate(root->right);
    }
    root = left_rotate(root);
  }
  C(root) = BLACK;
  C(L(root)) = RED;
  C(R(root)) = RED;
  return root;
}

Node *__insert(Node *root, int key) {
  if (root == NIL) {
    return getNewNode(key);
  }
  if (key > root->key) {
    root->right = __insert(root->right, key);
  } else if (key < root->key) {
    root->left = __insert(root->left, key);
  }
  return insert_maintain(root);
}

Node *insert(Node *root, int key) {
  root = __insert(root, key);
  root->color = BLACK;
  return root;
}

void out(Node *root) {
  if (root == NIL)
    return;
  cout << root->color << " | " << root->key << " | " << K(L(root)) << " | "
       << K(R(root)) << endl;
  out(L(root));
  out(R(root));
}

bool hasDoubleBlack(Node *root) {
  return C(L(root)) == DOUBLE_BLACK || C(R(root)) == DOUBLE_BLACK;
}

Node *erase_maintain(Node *root) {
  if (!hasDoubleBlack(root))
    return root;
  if (C(L(root)) == DOUBLE_BLACK && C(R(root)) == RED) {
    root = left_rotate(root);
    root->left = erase_maintain(root->left);
    return root;
  }
  if (C(R(root)) == DOUBLE_BLACK && C(L(root)) == RED) {
    root = right_rotate(root);
    root->right = erase_maintain(root->right);
    return root;
  }
  if (C(L(root)) == DOUBLE_BLACK) {
    if (C(R(root)) == BLACK && !hasRed(R(root))) {
      C(L(root))--;
      C(R(root))--;
      C(root)++;
      return root;
    }
    if (C(R(R(root))) == RED) {
      // RR;
      root = left_rotate(root);
    } else {
      // RL;
      root->right = right_rotate(root->right);
      root = left_rotate(root);
    }
    root->color = C(L(root));
    C(L(root)) = C(R(root)) = BLACK;
  } else {
    if (C(L(root)) == BLACK && !hasRed(L(root))) {
      C(R(root))--;
      C(L(root))--;
      C(root)++;
      return root;
    }
    if (C(L(L(root))) == RED) {
      // LL;
      root = right_rotate(root);
    } else {
      // LR;
      root->left = left_rotate(root->left);
      root = right_rotate(root);
    }
    root->color = C(R(root));
    C(R(root)) = C(L(root)) = BLACK;
  }

  return root;
}

Node *__erase(Node *root, int key) {
  if (root == NIL)
    return root;
  if (key < root->key) {
    root->left = __erase(root->left, key);
  } else if (key > root->key) {
    root->right = __erase(root->right, key);
  } else {
    if (L(root) == NIL || R(root) == NIL) {
      Node *tmp = L(root) == NIL ? R(root) : L(root);
      tmp->color++;
      free(root);
      return tmp;
    } else {
      Node *pre = root->left;
      while (pre->right) {
        pre = pre->right;
      }
      root->key = pre->key;
      root->left = __erase(root->left, pre->key);
    }
  }

  return erase_maintain(root);
}

Node *erase(Node *root, int key) {
  root = __erase(root, key);
  root->color = BLACK;
  return root;
}

int main() {
  Node *root = NIL;
  int tmp;
  while (1) {
    cin >> tmp;
    if (tmp == -1)
      break;
    root = insert(root, tmp);
  }
  out(root);

  while (1) {
    cin >> tmp;
    if (tmp == -1) {
      break;
    }
    root = erase(root, tmp);
    cout << endl;
    out(root);
  }
  return 0;
}
