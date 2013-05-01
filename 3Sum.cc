// Copyright 2013 Jike Inc. All Rights Reserved.
// Author: Shijun Zhang(zhangshijun@jike.com)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
  sort(num.begin(), num.end());
  vector<vector<int> > ret_vec;
  if (num.size() < 3) {
    return ret_vec;
  }
  for (vector<int>::iterator i = num.begin(); i <= num.end() - 2; i++) {
    for (vector<int>::iterator j = i + 2; j != num.end(); j++) {
      // cout << *i << " " << *j << " " << *(i+1) << " " << *(j-1) << endl;
      int temp_value = 0 - *i - *j;
      if (*(i + 1) == temp_value || *(j - 1) == temp_value ||
          binary_search(i + 1, j - 1, 0 - *i - *j)) {
        vector<int> tmp_vec;
        tmp_vec.push_back(*i);
        tmp_vec.push_back(0 - *i - *j);
        tmp_vec.push_back(*j);
        ret_vec.push_back(tmp_vec);
        while (j + 1 != num.end() && *j == *(j + 1)) {
          j++;
        }
      }
    }
    while (i + 1 != num.end() && *i == *(i + 1)) {
      i++;
    }
  }
  return ret_vec;
}

int main() {
  vector<int> num = {3,0,-2,-1,1,2};
  vector<vector<int> > ret = threeSum(num);
  for (int i = 0; i < ret.size(); i++) {
    for (int j = 0; j < ret[i].size(); j++) {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
}







