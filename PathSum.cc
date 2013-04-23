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



