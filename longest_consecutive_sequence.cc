// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : longest_consecutive_sequence.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/17 11:15:12

#include <iostream>
#include <vector>
// #include <unordered_map>
#include <ext/hash_map>

using namespace __gnu_cxx;
using namespace std;

int GetLongestSequence(hash_map<int, int>& int_map, int element,
    bool is_asc) {
  int count = 0;
  while (int_map[element]) {
    // int_map.erase(element);
    count += int_map[element];
    int_map[element] = 0;
    if (is_asc) {
      element++;
    } else {
      element--;
    }
  }
  // cout << element << " " << count << endl;
  return count;
}

int longestConsecutive(vector<int> &num)  {
  hash_map<int, int> int_map;
  for (int i = 0; i < num.size(); i++) {
    int_map.insert(pair<int, int>(num[i], 1));
  }
  int max_num = 0;
  for (int i = 0; i <  num.size(); i++) {
    max_num = max(max_num, GetLongestSequence(int_map, num[i], false) +
        GetLongestSequence(int_map, num[i]+1, true));
  }
  return max_num;
}

int main() {
  vector<int> num;
  num.push_back(100);
  num.push_back(4);
  num.push_back(200);
  num.push_back(1);
  num.push_back(3);
  num.push_back(2);
  cout << longestConsecutive(num) << endl;
  return false;
}
