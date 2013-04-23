// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : TwoSum.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/17 17:39:40

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
  vector<int> result;
  set<int> num_set;
  for (int i = 0; i < numbers.size(); i++) {
    num_set.insert(numbers[i]);
  }
  for (int i = 0; i < numbers.size(); i++) {
    if (num_set.count(target - numbers[i]) > 0) {
      result.push_back(i + 1);
      // cout << i <<" ";
      for (int j = i + 1; j < numbers.size(); j++) {
        if (numbers[j] == target - numbers[i]) {
          result.push_back(j + 1);
          // cout << j <<" ";
          break;
        }
      }
      break;
    }
  }
  return result;
}

int main() {
  vector<int> numbers;
  numbers.push_back(2);
  numbers.push_back(7);
  numbers.push_back(11);
  numbers.push_back(15);
  twoSum(numbers, 9);
}
