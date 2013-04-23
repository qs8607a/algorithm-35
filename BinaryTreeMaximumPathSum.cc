// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : BinaryTreeMaximumPathSum.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/17 17:30:48

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;


int FindPath(TreeNode *root, int& all_max) {
  if (root == NULL) {
    return 0;
  }
  int left_value = FindPath(root->left, all_max);
  int right_value = FindPath(root->right, all_max);
  int local_value = root->val;
  if (left_value > 0) {
    local_value += left_value;
  }
  if (right_value > 0) {
    local_value += right_value;
  }
  all_max = max(all_max, local_value);
  // half
  return max(root->val, max(root->val + left_value, root->val + right_value));
}

int maxPathSum(TreeNode *root) {
  int ret = root->val;
  FindPath(root, ret);
  return ret;
}
