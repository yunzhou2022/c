/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <cstring>
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int size = preorder.size();
    if (size == 0)
      return nullptr;
    Node *root = new TreeNode(preorder[0]);
    int pos;
    for (int i = 0; i < size; i++) {
      if (preorder[0] == inorder[i]) {
        pos = i;
        break;
      }
    }
    vector<int> pre, in;
    for (int i = 1; i <= pos; i++) {
      pre.push_back(preorder[i]);
    }
    for (int i = 0; i < pos; i++) {
      in.push_back(inorder[i]);
    }
    root->lchild = buildTree(pre, in);

    pre.clear();
    for (int i = pos + 1; i < size; i++) {
      pre.push_back(preorder[i]);
    }
    in.clear();
    for (int i = pos + 1; i < size; i++) {
      in.push_back(inorder[i]);
    }
    root->rchild = buildTree(pre, in);

    return root;
  }
};
