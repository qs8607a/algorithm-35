// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : max_no_repeated_str.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/14 16:55:32


#include <string>
#include <iostream>
#include <ext/hash_map>
#include <algorithm>
#include <string.h>
using namespace std;
using namespace __gnu_cxx;
// using namespace stdext;

// if a[i] not in map, max+1;
// else max = 1;
int lengthOfLongestSubstring(string s) {
  int n = s.size();
  vector<bool> exist(256, false);
  int max_num = 0;
  int i = 0, j = 0; //
  while (j < n) {
    max_num = max(max_num, j - i);
    if (exist[s[j]]) {
      while (s[i] != s[j]) {
        exist[s[i]] = false;
        i++;
      }
      i++;
      j++;
    } else {
      exist[s[j]] = true;
      j++;
    }
  }
  // cout << j << " " << n << endl;
  max_num = max(max_num, j - i);
  return max_num;
}

int main() {
  cout << lengthOfLongestSubstring("aaaaaa") << "1" << endl;
  cout << lengthOfLongestSubstring("abcde") << "5" << endl;
  cout << lengthOfLongestSubstring("abacde") << "4" << endl;
  cout << lengthOfLongestSubstring("abcdea") << "5" << endl;
  cout << lengthOfLongestSubstring("abcdeb") << "5" << endl;
  cout << lengthOfLongestSubstring("abcabcbb") << "3" << endl;
  cout << lengthOfLongestSubstring("ghykqfyvlstqrqwnfejvyeaieegsempntnxmvxjgrcwkuuzazivznxhtbpmicdxxrwjo") << " 12" << endl;
  return 0;
}
