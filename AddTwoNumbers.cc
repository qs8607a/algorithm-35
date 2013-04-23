// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : AddTwoNumbers.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/21 18:41:16


#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  if (l2 == NULL) {
    return l1;
  }
  if (l1 == NULL) {
    return l2;
  }
  int n1 = 0, n2 = 0, tmp;
  ListNode* head = NULL;
  ListNode* node = NULL;
  while (l1 != NULL || l2 != NULL) {
    tmp = n2;
    if (l1 != NULL) {
      tmp += l1->val;
    }
    if (l2 != NULL) {
      tmp += l2->val;
    }
    n1 = tmp % 10;
    if (head == NULL) {
      head = new ListNode(n1);
      node = head;
    } else {
      node->next = new ListNode(n1);
      node = node->next;
    }
    n2 = tmp / 10;
    if (l1 != NULL)
      l1 = l1->next;
    if (l2 != NULL)
      l2 = l2->next;
  }
  if (n2 != 0) {
    node->next = new ListNode(n2);
  }
  return head;
}
int main() {
  return 0;
}
