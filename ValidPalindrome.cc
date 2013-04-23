// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : ValidPalindrome.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/17 17:00:54

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (!isalnum(s[i])) {
      i++;
      continue;
    }
    if (!isalnum(s[j])) {
      j--;
      continue;
    }
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int main() {
  cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << isPalindrome("ab2a") << endl;
}
