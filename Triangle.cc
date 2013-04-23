// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : Triangle.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/19 10:47:19


#include <iostream>
#include <vector>
using namespace std;

int GetMinTotal(vector<vector<int> > &triangle, vector<vector<int> > &min_total,
    int m, int n) {
  if (m >= triangle.size()) {
    return 0;
  }
  if (n > m) {
    return 0;
  }
  if (min_total[m][n] != -1) {
    return min_total[m][n];
  }
  int left_value = GetMinTotal(triangle, min_total, m + 1, n);
  int right_value = GetMinTotal(triangle, min_total, m + 1, n + 1);
  int min_value = triangle[m][n] + min(left_value, right_value);
  min_total[m][n] = min_value;
  return min_value;
}

int minimumTotal(vector<vector<int> > &triangle) {
  int size = triangle.size();
  if (size == 0) {
    return 0;
  }
  vector<vector<int> > min_total(size, vector<int>(size, -1));
  return GetMinTotal(triangle, min_total, 0, 0);
}

int main() {
  vector<vector<int> > triangle = {
           {2},
          {3,4},
         {6,5,7},
        {4,1,8,3}
   };
  // vector<int> tmp;
  // tmp.push_back(2);
  // triangle.push_back(tmp);
  // tmp.clear();
  // tmp.push_back(3);
  // tmp.push_back(4);

  // tmp.push_back(6);
  // tmp.push_back(5);
  // tmp.push_back(7);
  // tmp.push_back();
  // tmp.push_back();
  // tmp.push_back();
  // tmp.push_back();
  // tmp.push_back();
  cout << minimumTotal(triangle) << endl;
}

