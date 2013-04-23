// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : palindrome_partitioning_1.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/16 17:01:4
// For example, given s = "aab",
// Return
//
//   [
//       ["aa","b"],
//       ["a","a","b"]
//   ]
#include <iostream>
#include <string>
#include <vector>
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

void GenPartition(const string& s, vector<vector<string> >& results,
    vector<string>& result, int begin) {
  if (begin == s.size()) {
    results.push_back(result);
    // for (int i = 0; i < result.size(); i++) {
    //   cout << result[i] << " ";
    // }
    // cout << endl;
  }
  for (int i = begin; i < s.size(); i++) {
    if (IsPalindrome(s, begin, i)) {
      result.push_back(s.substr(begin, i - begin + 1));
      GenPartition(s, results, result, i+1);
      result.pop_back();
    }
  }
}

vector<vector<string> > partition(string s) {
  map.clear();
  vector<int> tmp_vec(s.size(), -1);
  for (int i = 0; i < s.size(); i++) {
    map.push_back(tmp_vec);
  }
  vector<string> result;
  vector<vector<string> > results;
  GenPartition(s, results, result, 0);
  return results;
}

int main() {
  vector<vector<string> > results;
  results = partition("aab");
  results = partition("aabaa");
}
