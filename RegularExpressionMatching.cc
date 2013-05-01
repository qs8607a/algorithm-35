// Copyright 2013 Jike Inc. All Rights Reserved.
// Author: Shijun Zhang(zhangshijun@jike.com)


#include <iostream>
#include <string.h>

using namespace std;
// abc, a*c
bool isMatch(const char *s, const char *p) {
  if (*p == '\0') {
    return (*s == '\0');
  }
  // *p is *
  if (*p == '*') {
    //cout << "**** false\n";
    return false;
  }
  if (*(p + 1) != '*') {
    return (*p == *s || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
  }
  if (*(p + 1) == '*' && (*p == *s || (*p == '.'))) {
    while (*s != '\0' && (*p == *s || (*p == '.'))) {
      if (isMatch(s, p + 2)) {
        //cout << s << " VS1 " << p + 2 << endl;
        return true;
      }
      s++;
      //cout << "s++\n";
    }
    if (isMatch(s, p + 2)) {
      //cout << s << " VS2 " << p + 2 << endl;
      return true;
    }
  }
  if (*(p + 1) == '*' && *p != '.' && *p != *s) {
    //cout << s << " VS3 " << p + 2 << endl;
    return isMatch(s, p + 2);
  }
  //cout << "End false\n";
  return false;
}


int main() {
  cout << isMatch("aaa", "ab*ac*a") << endl;
  cout << isMatch("aaa", "a.a") << endl;
  cout << isMatch("aaa", "aa") << endl;
  cout << isMatch("ab", ".*") << endl;
  cout << isMatch("aaba", "ab*a*c*a") << endl;
  cout << isMatch("", ".*") << endl;
  return 0;
}








