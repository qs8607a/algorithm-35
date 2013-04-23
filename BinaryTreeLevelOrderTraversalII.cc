// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : PopulatingNextRightPointersinEachNode.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/20 11:19:37

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right, *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// void connect(TreeLinkNode *root) {
vector<vector<int> > levelOrderBottom(TreeNode *root) {
  vector<vector<int> > traversal_lists;
  vector<int> traversal_list;
  if (root == NULL) {
    return traversal_lists;
  }
  queue<TreeNode*> push_queue;
  queue<TreeNode*> pop_queue;
  pop_queue.push(root);
  while (pop_queue.size() > 0) {
    while (pop_queue.size() > 0) {
      TreeNode* pre = pop_queue.front();
      traversal_list.push_back(pre->val);
      pop_queue.pop();
      if (pre->left != NULL) {
        push_queue.push(pre->left);
      }
      if (pre->right != NULL) {
        push_queue.push(pre->right);
      }
    }
    swap(push_queue, pop_queue);
    traversal_lists.push_back(traversal_list);
    traversal_list.clear();
  }
  for (int i = 0, j = traversal_lists.size() - 1; i < j; i++, j--) {
    swap(traversal_lists[i], traversal_lists[j]);
  }
  return traversal_lists;
}

int main() {
  return 0;
}







