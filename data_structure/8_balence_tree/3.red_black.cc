#include <iostream>
using namespace std;

#define RED 0
#define BLACK 1
#define DBlack 2

typedef struct Node {
  int key;
  Node *left, *right;
  int color;
} Node;

Node tmp;
Node *NIL;
__attribute__((constructor)) void __init() {
  NIL = &tmp;
  NIL->color = BLACK;
  NIL->left = NIL->right = NIL;
  NIL->key = -1;
}

Node *getNewNode(int key) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->color = RED;
  p->left = p->right = NIL;
  p->key = key;
  return p;
}

void clear(Node *root) {
  if (root == NIL)
    return;
  clear(root->left);
  clear(root->right);
  free(root);
}

#define K(n) (n->key)
#define C(n) (n->color)
#define L(n) (n->left)
#define R(n) (n->right)

bool child_has_red(Node *n) { return C(L(n)) == RED || C(R(n)) == RED; }

Node *left_rotate(Node *root) {
  Node *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  return newRoot;
}

Node *right_rotate(Node *root) {
  Node *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  return newRoot;
}

Node *insert_update(Node *root) {
  if (!child_has_red(root))
    return root;
  int flag = 0;
  if (C(L(root)) == RED && child_has_red(L(root)))
    flag = 1;
  if (C(R(root)) == RED && child_has_red(R(root)))
    flag = 2;
  if (flag == 0)
    return root;
  if (flag == 1) {
    if (C(R(root)) == RED) {
      C(root) = RED;
      C(L(root)) = BLACK;
      C(R(root)) = BLACK;
      return root;
    }
    if (C(R(L(root))) == RED) {
      root->left = left_rotate(root->left);
    }
    root = right_rotate(root);
  } else {
    if (C(L(root)) == RED) {
      C(root) = RED;
      C(R(root)) = BLACK;
      C(L(root)) = BLACK;
      return root;
    }
    if (C(L(R(root))) == RED) {
      root->right = right_rotate(root->right);
    }
    root = left_rotate(root);
  }
  C(root) = RED;
  C(L(root)) = BLACK;
  C(R(root)) = BLACK;
  return root;
}

Node *__insert(Node *root, int key) {
  if (root == NIL)
    return getNewNode(key);
  if (key < root->key) {
    root->left = __insert(root->left, key);
  } else {
    root->right = __insert(root->right, key);
  }
  return insert_update(root);
}

Node *insert(Node *root, int key) {
  root = __insert(root, key);
  root->color = BLACK;
  return root;
}

Node *pre(Node *root) {
  Node *tmp = root->left;
  while (tmp->right != NIL)
    tmp = tmp->right;
  return tmp;
}

Node *erase_maintain(Node *root) {
  if (C(L(root)) != DBlack && C(R(root)) != DBlack) {
    return root;
  }
  if (child_has_red(root)) {
    root->color = RED;
    if (root->left->color == RED) {
      root = right_rotate(root);
      root->right = erase_maintain(root->right);
    } else {
      root = left_rotate(root);
      root->left = erase_maintain(root->left);
    }
    root->color = BLACK;
    return root;
  }
  if (root->left->color == DBlack && !child_has_red(root->right) ||
      root->right->color == DBlack && !child_has_red(root->left)) {
    root->color++;
    root->left->color--;
    root->right->color--;
    return root;
  } else if (root->left->color == DBlack) {
    root->left->color = BLACK;
    if (root->right->left->color == RED && root->right->right->color != RED) {
      root->right = right_rotate(root->right);
    }
    root->right->color = root->color;
    // root->color = root->right->right->color = BLACK;
    root = left_rotate(root);
  } else if (root->right->color == DBlack) {
    root->right->color = BLACK;
    if (root->left->right->color == RED && root->left->left->color != RED) {
      root->left = left_rotate(root->left);
    }
    root->left->color = root->color;
    // root->color = root->left->left->color = BLACK;
    root = right_rotate(root);
  }
  root->left->color = root->right->color = BLACK;
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
    if (root->left == NIL || root->right == NIL) {
      Node *tmp = root->left == NIL ? root->right : root->left;
      tmp->color += root->color;
      free(root);
      return tmp;
    } else {
      Node *tmp = pre(root);
      root->key = tmp->key;
      root->left = __erase(root->left, tmp->key);
    }
  }
  return erase_maintain(root);
}

Node *erase(Node *root, int key) {
  root = __erase(root, key);
  root->color = BLACK;
  return root;
}

void out(Node *root) {
  if (root == NIL) {
    return;
  }
  printf("%d[%d, %d, %d]\n", K(root), C(root), K(L(root)), K(R(root)));
  out(root->left);
  out(root->right);
}

int main() {
  int k;
  Node *root = NIL;
  int arr[10] = {1, 2, 3, 4, 5, 6, -1};
  int i = 0;
  while (1) {
    int k = arr[i++];
    // cin >> k;
    if (k == -1)
      break;
    root = insert(root, k);
  }
  out(root);

  int x = 1;
  // while (~scanf("%d", &x)) {
  printf("\nerase %d from red black tree\n", x);
  root = erase(root, 1);
  cout << endl;
  out(root);
  root = erase(root, 2);
  cout << endl;
  out(root);
  //  }

  return 0;
}
