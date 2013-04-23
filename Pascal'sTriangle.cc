// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : Pascal'sTriangle.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/19 11:28:17


#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
  vector<vector<int> > triangle;
  if (numRows <= 0) {
    return triangle;
  }
  vector<int> tmp_vector;
  tmp_vector.push_back(1);
  triangle.push_back(tmp_vector);
  for (int i = 1; i < numRows; i++) {
    tmp_vector.clear();
    for (int j = 0; j <= i; j++) {
      int tmp = 0;
      if (j - 1 >= 0) {
        tmp += triangle[i - 1][j - 1];
      }
      if (j <= i - 1) {
        tmp += triangle[i - 1][j];
      }
      tmp_vector.push_back(tmp);
    }
    triangle.push_back(tmp_vector);
  }
  // for (int i = 0; i < triangle.size(); i++) {
  //   for (int j = 0; j < triangle[i].size(); j++)
  //     cout << triangle[i][j] << " ";
  //   cout << endl;
  // }
  return triangle;
}


int main() {
  generate(4);
  generate(1000);
}


