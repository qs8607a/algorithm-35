/***************************************************************************
 * 
 * Copyright (c) 2012 jike.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file max_seq_sum.cc
 * @author zhangshijun(zhangshijun@jike.com)
 * @date 2012/06/12 11:15:08
 * @version $Revision$ 
 * @brief 
 *  
 **/
#include <iostream>
#include <cstring>
using namespace std;

int max_seq_sum(int a[], int len) {
  int max = a[0];
  int sum = 0;
  
  for (int i = 0; i < len; i++) {
    sum += a[i];
    if (sum > max) {
      max = sum;
    }
    if (a[i] > max) {
      max = a[i];
    }
    if (sum < 0) {
      sum = 0;
    }
  }
  
  if (0 == max) {
    max = a[0];
    for (int i = 0; i < len; i++) {
      if (a[i] > max) {
        max = a[i];
      }
    }
  }
  return max;
}

// sum = max {sum + a[i], a[i]}
int max_seq(int a[], int len) {
	int i, sum = a[0], max_sum = a[0];
	for (i = 1; i < len; i++) {
		sum = max(sum + a[i], 0);
		max_sum = max(max_sum, a[i]);
		max_sum = max(max_sum, sum);
	}
	if (max_sum == 0) {
    max_sum = a[0];
    for (int i = 0; i < len; i++) {
      if (a[i] > max_sum) {
        max_sum = a[i];
      }
    }
	}
	return max_sum;
}

// 
int max_seq_2(int a[], int len) {
	int i, sum = a[0], max_sum = a[0];
	for (i = 1; i < len; i++) {
		sum = max(sum + a[i], a[i]);
		// max_sum = max(max_sum, a[i]);
		max_sum = max(max_sum, sum);
	}
	// if (max_sum == 0) {
    // max_sum = a[0];
    // for (int i = 0; i < len; i++) {
    //   if (a[i] > max_sum) {
    //     max_sum = a[i];
    //   }
    // }
	// }
	return max_sum;
}

int main() {
  int a[] = {10, -2, -3};
  int b[] = {-10, -2, -3};
  int c[] = {3, -2, 10};
  cout << max_seq_sum(a, 3) << endl; 
  cout << max_seq_sum(b, 3) << endl; 
  cout << max_seq_sum(c, 3) << endl; 
  cout << max_seq(a, 3) << endl; 
  cout << max_seq(b, 3) << endl; 
  cout << max_seq(c, 3) << endl; 
  cout << max_seq_2(a, 3) << endl; 
  cout << max_seq_2(b, 3) << endl; 
  cout << max_seq_2(c, 3) << endl; 
}










/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
