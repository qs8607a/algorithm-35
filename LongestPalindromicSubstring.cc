// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : LongestPalindromicSubstring.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/21 19:02:40


#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<char> > map;
int IsPalindrome(const string&s, int i, int j) {
  if (map[i][j] != 2) {
    return map[i][j];
  }
  if (i == j) {
    map[i][j] = 1;
    return 1; 
  }
  if (s[i] != s[j]) {
    map[i][j] = 0;
    return 0;
  } else {
    if (j - i == 1) {
      map[i][j] = 1;
      return 1;
    } else {
      map[i][j] = IsPalindrome(s, i + 1, j - 1);
    }
  } 
  return map[i][j];
}

string longestPalindrome(string s) {
  int n = s.size();
  if (n == 0) {
    return "";
  }
  map.clear();
  vector<char> tmp_vec(s.size(), 2);
  for (int i = 0; i < s.size(); i++) {
    map.push_back(tmp_vec);
  }
  // for (int i = 0; i < n; i++) {
  //   cout << map[0][i] << endl;
  // }
  for (int i = n; i > 0; i--) {
    for (int j = 0; i + j <= n; j++) {
      // cout << j << " " << i + j - 1 << " " << IsPalindrome(s, j, i + j - 1) << endl;
      if (IsPalindrome(s, j, i + j - 1) == 1) {
        return s.substr(j, i);
      }
    }
  }
  return "";
}

int main() {
  cout << longestPalindrome("aab") << endl;
  cout << longestPalindrome("aabaa") << endl;
  cout << longestPalindrome("a") << endl;
}
