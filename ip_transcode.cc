// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : ip_transcode.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/02 22:19:06



#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

const int kOffset = 8;

bool IsValidChar(char s) {
  if (s >= '0' && s <= '9') {
    return true;
  }
  return false;
}

int IPTranscode(const string& ip_str) {
  int begin = 0, end = 0;
  int ip = 0;
  int count = 0;
  int i;
  for (i = 0; i < ip_str.size(); i++) {
    if (ip_str[i] == '.') {
      if (i - begin <= 0) {
        return -1;
      }
      string tmp = ip_str.substr(begin, i - begin);
      ip <<= kOffset;
      ip += atoi(tmp.data());
      count++;
      begin = i + 1;
    } else if (!IsValidChar(ip_str[i])) {
      return -1;
    }
  }
  string tmp = ip_str.substr(begin, i - begin);
  ip <<= kOffset;
  ip += atoi(tmp.data());
  count++;
  if (count != 4) {
    return -1;
  }
  return ip;
}

int main() {
  cout << IPTranscode("0.0.0.10") << endl;
  cout << IPTranscode(".0.0.10") << endl;
  cout << IPTranscode("10.0.0.0") << endl;
  cout << IPTranscode("10.x.0.0") << endl;
  cout << IPTranscode("...") << endl;
  cout << IPTranscode("192.168.1.1") << endl;
  return 0;
}
