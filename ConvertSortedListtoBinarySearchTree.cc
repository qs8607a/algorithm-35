// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : PathSum.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/20 13:59:21

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *BuildBST(ListNode* &node, int start, int end) {
  if (start > end || end < 0) {
    return NULL;
  }
  int mid = start + (end - start) / 2;
  TreeNode* left_child = BuildBST(node, start, mid - 1);
  TreeNode* parent = new TreeNode(node->val);
  node = node->next;
  parent->left = left_child;
  parent->right = BuildBST(node, mid + 1, end);
  return parent;
}

TreeNode *sortedListToBST(ListNode *head) {
  if (head == NULL) {
  }
  ListNode* tmp_node = head;
  int n = 0;
  while(tmp_node) {
    tmp_node = tmp_node->next;
    n++;
  }
  return BuildBST(head, 0, n - 1);
}

int main() {
  return 0;
}



