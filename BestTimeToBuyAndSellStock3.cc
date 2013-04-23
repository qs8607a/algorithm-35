// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : BestTimeToBuyAndSellStock3.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/18 19:58:41

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices) {
  int n = prices.size();
  if (n == 0) {
    return 0;
  }
  vector<int> profit(n, 0);
  int cur = prices[0], diff = 0;
  for (int i = 1; i < n; i++) {
    if (cur > prices[i]) {
      cur = prices[i];
    } else {
      diff = max(diff, prices[i] - cur);
    }
    profit[i] = diff;
  }
  cur = prices[n - 1];
  diff = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (cur < prices[i]) {
      cur = prices[i];
    } else {
      diff = max(diff, cur - prices[i]);
    }
    profit[i] += diff;
  }
  return *max_element(profit.begin(), profit.end());
}

int main() {
  vector<int> prices;
  prices.push_back(2);
  prices.push_back(1);
  cout << maxProfit(prices) << endl;
}









