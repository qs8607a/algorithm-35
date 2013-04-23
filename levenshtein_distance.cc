// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : levenshtein_d.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/03/31 23:35:25

#include <iostream>
#include <string>

using namespace std;

int d[10000][10000];

// ab abbb 这种情况存在问题, 需要通过下标
int CalcDistance(string a, string b) {
  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      int cost = 0;
      if (a[i-1] != b[j-1]) {
        cost = 1;
      }
      d[i][j] = d[i-1][j] + 1 > d[i][j-1] + 1 ?
        d[i][j-1] + 1 : d[i-1][j] + 1;
      d[i][j] = d[i][j] > d[i-1][j-1] + cost ?
        d[i-1][j-1] + cost : d[i][j];
    }
  }
  return d[a.size()][b.size()];
}

// correct
int CalcDistance2(string a, int a_begin, int a_end,
    string b, int b_begin, int b_end) {
  if (a_begin > a_end) {
    if (b_begin > b_end)
      return 0;
    else 
      return b_end - b_begin + 1;
  }
  if (b_begin > b_end) {
    if (a_begin > a_end)
      return 0;
    else 
      return a_end - a_begin + 1;
  }
  if (a[a_begin] == b[b_begin])
    return CalcDistance2(a, a_begin + 1, a_end,
        b, b_begin + 1, b_end);
  else {
    int t1 = CalcDistance2(a, a_begin + 1, a_end,
        b, b_begin, b_end);
    int t2 = CalcDistance2(a, a_begin, a_end,
        b, b_begin + 1, b_end);
    int t3 = CalcDistance2(a, a_begin + 1, a_end,
        b, b_begin + 1, b_end);
    int min = t1 > t2 ? t2 : t1;
    return (min > t3 ? t3 : min) + 1;
  }
}

int main() {
  string a, b;
  while (cin >>a >> b) {
    cout << CalcDistance(a, b) << endl;
    cout << CalcDistance2(a, 0, a.size(), b, 0, b.size()) << endl;
    for (int i = 1; i <= a.size(); i++) {
      for (int j = 1; j <= b.size(); j++) {
        cout << d[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
