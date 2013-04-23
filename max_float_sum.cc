// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : max_float_sum.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/02 09:08

// 给定一个float数组，求连续子数组乘积最大值（不考虑溢出）
// max[i] = max {a[i], min[i-1]*a[i], max[i-1]*a[i]}
// min[i] = min {a[i], min[i-1]*a[i], max[i-1]*a[i]}

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int float_max[100], float_min[100];

bool GetMaxFloatMulti(int a[], int len) {
  if (len < 1) {
    return false;
  }
  float_max[0] = a[0];
  float_min[0] = a[0];
  int tmp, i;
  for (i = 1; i < len; i++) {
    tmp = max(a[i], a[i] * float_max[i-1]);
    float_max[i] = max(tmp, a[i] * float_min[i-1]);
    tmp = min(a[i], a[i] * float_max[i-1]);
    float_min[i] = min(tmp, a[i] * float_min[i-1]);
  }
  cout << "max:" << float_max[i-1] << endl;
  cout << "min:" << float_min[i-1] << endl;
  return true;
}

int main() {
  int a[] = {10, -5, -5, 2, -100, -1};
  memset(float_max, 0, sizeof(float_max));
  memset(float_min, 0, sizeof(float_min));
  GetMaxFloatMulti(a, sizeof(a)/sizeof(int));

  int b[] = {-1};
  memset(float_max, 0, sizeof(float_max));
  memset(float_min, 0, sizeof(float_min));
  GetMaxFloatMulti(b, sizeof(b)/sizeof(int));

  return 0;
}
