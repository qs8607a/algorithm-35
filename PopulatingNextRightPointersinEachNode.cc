// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : PopulatingNextRightPointersinEachNode.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/20 11:19:37

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
  if (root == NULL) {
    return;
  }
  queue<TreeLinkNode*> push_queue;
  queue<TreeLinkNode*> pop_queue;
  pop_queue.push(root);
  while (pop_queue.size() > 0) {
    while (pop_queue.size() > 0) {
      TreeLinkNode* pre = pop_queue.front();
      pop_queue.pop();
      TreeLinkNode* next = NULL;
      if (pop_queue.size() > 0) {
        next = pop_queue.front();
      }
      pre->next = next;
      if (pre->left != NULL) {
        push_queue.push(pre->left);
      }
      if (pre->right != NULL) {
        push_queue.push(pre->right);
      }
    }
    swap(push_queue, pop_queue);
  }
}

int main() {
  return 0;
}







