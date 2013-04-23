// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : PathSum.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/20 13:59:21

#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool GetIsBalanced(TreeNode *root, int& depth) {
  if (root == NULL) {
    depth = 0;
    return true;
  }
  int left_depth = 0, right_depth = 0;
  bool is_balanced = GetIsBalanced(root->left, left_depth);
  is_balanced &= GetIsBalanced(root->right, right_depth);
  depth = max(left_depth + 1, right_depth + 1);
  if (!is_balanced || abs((double)left_depth - (double)right_depth) > 1) {
    return false;
  }
  return true;
}

bool isBalanced(TreeNode *root) {
  if (root == NULL) {
    return true;
  }
  int depth = 0;
  return GetIsBalanced(root, depth);
}

bool hasPathSum(TreeNode *root, int sum) {
  if (root == NULL) {
    return false;
  }
  if (sum == root->val && root->left == NULL && root->right == NULL) {
    return true;
  }
  sum -= root->val;
  return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

int main() {
  return 0;
}



