// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : MedianofTwoSortedArrays.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/18 00:18:21

#include <iostream>
using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
  if (m == 0 && n == 0) {
    return 0;
  }
  bool plus_flag = (m + n - 1) % 2;
  int median_index = (m + n - 1) / 2;
  double median = 0.0f;
  int i = 0, j = 0, index = 0;
  while(index <= (m + n) / 2) {
    int value;
    if (i < m && j < n) {
      if (A[i] < B[j]) {
        value = A[i++];
      } else {
        value = B[j++];
      }
    } else if (i < m) {
      value = A[i++];
    } else if (j < n) {
      value = B[j++];
    }
    if (index == median_index) {
      median += value;
    }
    if (index == median_index + 1 && plus_flag) {
      median += value;
      median /= 2.0;
    }
    index++;
  }
  return median;
}

int main() {
  int a[] = {1};
  int b[] = {2, 3};
  cout << findMedianSortedArrays(a, 1, b, 2) << endl;
}
