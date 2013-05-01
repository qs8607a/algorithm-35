// Copyright 2013 Jike Inc. All Rights Reserved.
// Author: Shijun Zhang(zhangshijun@jike.com)




#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
  int i, j;
  if (strs.size() == 0) {
    return "";
  }
  if (strs[0].size() == 0) {
    return "";
  }
  for (i = 0; i < strs[0].size(); i++) {
    for (int j = 1; j < strs.size(); j++) {
      if (strs[j][i] != strs[0][i]) {
        return strs[0].substr(0, i);
      }
    }
  }
  return strs[0].substr(0, i);
}

int main() {
  vector<string> str;
  str.push_back("hello");
  str.push_back("");
  cout << longestCommonPrefix(str) << endl; 
}






