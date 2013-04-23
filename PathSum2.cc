// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : PathSum.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/20 13:59:21

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void GetPathSum(TreeNode *root, vector<vector<int> >& paths,
    vector<int> path, int sum) {
  if (root == NULL) {
    return;
  }
  if (sum == root->val && root->left == NULL && root->right == NULL) {
    path.push_back(root->val);
    paths.push_back(path);
    return;
  }
  sum -= root->val;
  path.push_back(root->val);
  GetPathSum(root->left, paths, path, sum);
  GetPathSum(root->right, paths, path, sum);
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
  vector<vector<int> > paths;
  vector<int> path;
  GetPathSum(root, paths, path, sum);
  return paths;
}

int main() {
  return 0;
}



