// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : equation.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/15 13:14:09
// http://leetcode.com/onlinejudge#question_132

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > map;

int IsPalindrome(const string&s, int i, int j) {
  if (map[i][j] != -1) {
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

// min_cut[i][j] = min(min_cut[i][k] + min_cut[k+1][j] + 1);
int minCut(const string& s) {
  map.clear();
  vector<int> tmp_vec(s.size(), -1);
  vector<int> result_vec;
  for (int i = 0; i < s.size(); i++) {
    result_vec.push_back(i);
    map.push_back(tmp_vec);
  }
  for (int i = 1; i < s.size(); i++) {
    if (IsPalindrome(s, 0, i)) {
      result_vec[i] = 0;
    } else {
      int tmp = 0, ans = i;
      for (int j = 0; j < i; j++) {
        if (IsPalindrome(s, j+1, i)) {
          tmp = result_vec[j] + 1;
        } else {
          tmp = result_vec[j] + i - j;
        }
        if (ans > tmp) {
          ans = tmp;
        }
      }
      result_vec[i] = min(ans, result_vec[i]);
    }
  }
  return result_vec[s.size() - 1];
}
int main() {
  cout << minCut("aab") << endl;
  cout << minCut("aa") << endl;
  cout << minCut("a") << endl;
  cout << minCut("aabaa") << endl;
  cout << minCut("ababbbabbaba") << endl;
  cout << minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
}
