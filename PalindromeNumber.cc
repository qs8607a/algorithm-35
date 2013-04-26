// Copyright 2013 Jike Inc. All Rights Reserved.
// Author: Shijun Zhang(zhangshijun@jike.com)

#include <iostream>
using namespace std;

bool isPalindrome(int x, int& y) {
  if (x < 0) {
    return false;
  }
  if (x == 0) {
    return true;
  }
  if (isPalindrome(x/10, y) && (x % 10) == (y % 10)) {
    y /= 10;
    return true;
  } else {
    return false;
  }
}

bool isPalindrome(int x) {
  return isPalindrome(x, x);
}

int main() {
  cout << isPalindrome(111) << endl;
  cout << isPalindrome(121) << endl;
  cout << isPalindrome(1211) << endl;
}

