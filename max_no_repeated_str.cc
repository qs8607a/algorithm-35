// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : max_no_repeated_str.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/14 16:55:32
//
// see LongestSubstringWithoutRepeatingCharacters.cc
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
int GetNoRepeatedStrMaxCount(const string& str) {
  int max_num_array[str.size()];
  memset(max_num_array, 0, sizeof(max_num_array));
  int max_num = 0;
  hash_map<char, int> char_map;
  for (int i = 0; i < str.size(); i++) {
    if (char_map[str[i]] == 0) {
      max_num++;
      char_map[str[i]] = 1;
    } else {
      max_num = 1;
      char_map.clear();
      char_map[str[i]] = 1;
    }
    max_num_array[i] = max_num;
  }
  for (int i = 0; i < str.size(); i++) {
    if (max_num_array[i] > max_num) {
      max_num = max_num_array[i];
    }
  }
  return max_num;
}
int lengthOfLongestSubstring(string s) {
    int n = s.length();
      int i = 0, j = 0;
        int maxLen = 0;
          bool exist[256] = { false };
            while (j < n) {
                  if (exist[s[j]]) {
                          maxLen = max(maxLen, j-i);
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
              maxLen = max(maxLen, n-i);
                return maxLen;
}

int main() {
  cout << GetNoRepeatedStrMaxCount("aaaaaa") << "1" << endl;
  cout << GetNoRepeatedStrMaxCount("abcde") << "5" << endl;
  cout << GetNoRepeatedStrMaxCount("abacde") << "4" << endl;
  cout << GetNoRepeatedStrMaxCount("abcdea") << "5" << endl;
  cout << GetNoRepeatedStrMaxCount("abcdeb") << "5" << endl;
  cout << GetNoRepeatedStrMaxCount("abcabcbb") << "3" << endl;
  cout << GetNoRepeatedStrMaxCount("abcadef") << " 6" << endl;
  cout << lengthOfLongestSubstring("abcadefa") << " 6" << endl;
  return 0;
}
