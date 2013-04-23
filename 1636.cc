// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : 1636.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/01 19:44:33
// http://www.cnblogs.com/zhaoguanqin/archive/2012/04/03/2430895.html

#include <iostream>
#include <string.h>
using namespace std;

int map[250][250];  // dangerous pairs
int dp[250][250];  // dp[i][j]表示第一个监狱用i个人和第二个监狱j个人交换是否成功
int s1[250];  // 是否替换
int s2[250];

int n, m, l, r;

// 首先用dfs搜出各组有牵连的关系
void dfs(int x, int temp) {
  int i;
  if (temp == 1) {
    s1[x] = true;
  } else {
    s2[x] = true;
  }
  if (temp == 1) {
    r++;
    for (i = 0; i <= n; i++) {
      if (map[i][x] && !s2[i]) {
        dfs(i, 2);
      }
    }
  } else {
    l++;
    for (i = 0; i <= n; i++) {
      if (map[x][i] && !s1[i])
        dfs(i, 1);
    }
  }
}

int main() {
  int scenarios;
  cin >> scenarios;
  while(scenarios--) {
    cin >> n >> m;
    memset(map, false, sizeof(map));
    memset(dp, false, sizeof(dp));
    memset(s1, false, sizeof(s1));
    memset(s2, false, sizeof(s2));
    int x, y;
    for (int i = 1; i <= m; i++) {
      cin >> x >> y;
      map[x][y] = true; // 这里要注意 必须要赋值成单向  因为两个监狱的编号是相同的
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
      if(s1[i])
        continue;
      l = 0, r = 0; // a 监狱人数， b 监狱人数
      dfs(i, 1);
      for (int j = n/2; j >= l; j--) {
        for (int k = n/2; k >= r; k--) {
          if (dp[j-l][k-r])
            dp[j][k] = true;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if(s2[i])
        continue;
      l = 0, r = 0;
      dfs(i, 2);
      for (int j = n/2; j >= l; j--) {
        for (int k = n/2; k >= r; k--) {
          if (dp[j-l][k-r])
            dp[j][k] = true;
        }
      }
    }
    int i;
    for (i = n/2; i >= 0; i--) {
      if (dp[i][i]) {
        break;
      }
    }
    cout << i << endl;
  }
  return 0;
}
