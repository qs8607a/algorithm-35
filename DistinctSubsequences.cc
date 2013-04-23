// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : DistinctSubsequences.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/20 13:32:29

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numDistinct(string S, string T) {
  vector<vector<int> > dp(T.size(), vector<int>(S.size(), 0));
  for (int i = 0; i < T.size(); i++) {
    for (int j = 0; j < S.size(); j++) {
      if (T[i] == S[j]) {
        if (i - 1 < 0) {
          dp[i][j] = 1;
        } else {
          for (int k = 0; k < j; k++)
            dp[i][j] += dp[i-1][k];
        }
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < S.size(); i++) {
    sum += dp[T.size() - 1][i];
  }
  return sum;
}

int main() {
  cout << numDistinct("rabbbit", "rabbit") << endl;
  cout << numDistinct("rabbbit", "rabbit") << endl;
  cout << numDistinct("rabbbit", "rabbit") << endl;
}









