// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : permunation.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/03/26 14:43:03




#include <iostream>
using namespace std;

void permunation(char* pStr, char* pBegin) {
  if (pStr == NULL || pBegin == NULL) {
    return;
  }
  if (*pBegin == '\0') {
    cout << pStr << endl;
  }
  for (char* i = pBegin; *i != '\0'; i++) {
    swap(*pBegin, *i);
    permunation(pStr, pBegin + 1);
    swap(*pBegin, *i);
  }
}

int main() {
  char str[] = "abcdefghijklmn";
  permunation(str, str);
  return 0;
}








