// Copyright 2013 Jike Inc. All Rights Reserved.
// Author: Shijun Zhang(zhangshijun@jike.com)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
  sort(num.begin(), num.end());
  vector<vector<int> > ret_vec;
  if (num.size() < 4) {
    return ret_vec;
  }
  for (vector<int>::iterator i = num.begin(); i <= num.end() - 3; i++) {
    for (vector<int>::iterator j = i + 3; j != num.end(); j++) {
      for (vector<int>::iterator k = i + 2; k < j; k++) {
        // cout << *i << " " << *j << " " << *(i+1) << " " << *(j-1) << endl;
        int temp_value = target - *i - *j - *k;
        if (*(i + 1) > temp_value || *(k - 1) < temp_value) continue;
        if (*(i + 1) == temp_value || *(k - 1) == temp_value ||
            binary_search(i + 1, k - 1, temp_value)) {
          vector<int> tmp_vec;
          tmp_vec.push_back(*i);
          tmp_vec.push_back(temp_value);
          tmp_vec.push_back(*k);
          tmp_vec.push_back(*j);
          ret_vec.push_back(tmp_vec);
          while (k + 1 != num.end() && *k == *(k + 1)) {
            k++;
          }
        }
      }
      // while (j + 1 != num.end() && *j == *(j + 1)) {
      //   j++;
      // }
    }
    // while (i + 1 != num.end() && *i == *(i + 1)) {
    //   i++;
    // }
  }
  sort(ret_vec.begin(), ret_vec.end());
  ret_vec.erase(unique(ret_vec.begin(), ret_vec.end()), ret_vec.end());
  return ret_vec;
}

int main() {
  vector<int> num = {-1,2,2,-5,0,-1,4};
  vector<vector<int> > ret = fourSum(num, 3);
  for (int i = 0; i < ret.size(); i++) {
    for (int j = 0; j < ret[i].size(); j++) {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
}







