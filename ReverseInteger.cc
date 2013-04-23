// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : ReverseInteger.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/21 22:16:30

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int reverse(int x) {
  char buffer[1024];
  snprintf(buffer, sizeof(buffer), "%d", x);
  int start = 0;
  if (buffer[0] == '-' || buffer[0] == '+') {
    start++;
  }
  for (int i = start, j = strlen(buffer) - 1; i < j; i++, j--) {
    swap(buffer[i], buffer[j]);
  }
  return atoi(buffer);
}

int main() {
  char buffer[] = "-003";
  cout << atoi(buffer) << endl;
  cout << reverse(123) << endl;
  cout << reverse(-123) << endl;
}















