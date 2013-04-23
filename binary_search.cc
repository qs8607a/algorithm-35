// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : binary_search.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/02 11:30:26

#include <iostream>
using namespace std;

int BinarySearch(const int a[], int len, int start, int end) {
  if (start >= end) {
    if (start < len && start >= 0) {
      return a[start];
    } else {
      return 0;
    }
  }
  int mid = (end - start) / 2 + start;
  if (a[mid] <= a[start]) {
    cout << "mid:" << mid << " start:" << start << endl;
    return BinarySearch(a, len, start, mid);
  }
  if (a[mid] >= a[end]) {
    cout << "mid:" << mid << " end:" << end << endl;
    return BinarySearch(a, len, mid, end);
  }
}

int BinarySearch2(const int a[], int len) {
  if (a == NULL || len < 1) {
    return 0;
  }
  int start = 0, end = len - 1;
  while (start < end) {
    int mid = (end - start) / 2 + start;
    if (a[mid] <= a[start]) {
      end = mid;
    } else {
      start = mid;
    }
  }
  int tmp = a[start];
  
  // start = 0;
  // end = len - 1;
  // while (start < end) {
  //   int mid = (end - start) / 2 + start;
  //   if (a[mid] >= a[end]) {
  //     start = mid + 1;
  //   } else {
  //     end = mid - 1;
  //   }
  // }
  // return tmp > a[start] ? tmp : a[start];
  return tmp;
}

// {7, 11, 13, 17, 2, 3, 5}
// 假设数组中不存在相同的元素
int SearchInRotatedSortArray(int array[], int start, int end, int target) {
  while (start <= end) {
    int mid = (start + end) / 2;
    if (target == array[mid]) {
      return mid;
    }
    if (target < array[mid]) {
      // high is sorted
      if (array[mid] < array[end]) {
        end = mid - 1;
      } else { // lower is sorted
        if (array[start] > array[mid]) {

        } else if (array[start] < = array[mid])
      }
    }
  }
}

int main() {
  // find start of seq, expect: 1
  int a[] = {7, 8, 9, 1, 2, 3, 4, 5};
  int len = sizeof(a)/sizeof(int);
  cout << BinarySearch(a, len, 0, len - 1) << endl;
  cout << BinarySearch2(a, len) << endl;
  int b[] = {7, 8, 9, 9, 1, 1, 2, 3, 4, 7};
  len = sizeof(b)/sizeof(int);
  cout << BinarySearch(b, len, 0, len - 1) << endl;
  cout << BinarySearch2(b, len) << endl;
}
