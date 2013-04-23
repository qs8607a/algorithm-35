// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : PathSum.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/20 13:59:21

#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  if (root->left == NULL && root->right == NULL) {
    return 1;
  }
  int left_depth = -1, right_depth = -1;
  if (root->left != NULL) {
    left_depth = minDepth(root->left);
  }
  if (root->right != NULL) {
    right_depth = minDepth(root->right);
  }
  if (left_depth == -1) {
    return right_depth + 1;
  }
  if (right_depth == -1) {
    return left_depth + 1;
  }
  return min(left_depth + 1, right_depth + 1);
}

int main() {
  return 0;
}



