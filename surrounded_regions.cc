// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : surrounded_regions.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/16 23:17:30
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int m, n;
// 由边上的O进行传递搜索标记, 其他都是X
// DFS
void dfs(vector<vector<char> > &board, int i, int j) {
  if (i < 0 || i >= m || j < 0 || j >= n) {
    return;
  }
  if (board[i][j] == 'O') {
    board[i][j] = '#';
    dfs(board, i - 1, j);
    dfs(board, i + 1, j);
    dfs(board, i, j - 1);
    dfs(board, i, j + 1);
  }
}
void solve(vector<vector<char> > &board) {
  m = board.size();
  if (m == 0) {
    return;
  }
  n = board[0].size();
  
  // 边
  for (int i = 0; i < m; i++) {
    dfs(board, i, 0);
    dfs(board, i, n - 1);
  }
  for (int i = 0; i < n; i++) {
    dfs(board, 0, i);
    dfs(board, m - 1, i);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '#') {
        board[i][j] = 'O';
      } else if (board[i][j] == 'O') {
        board[i][j] = 'X';
      }
    }
  }
}

int main() {
  char a[4][4] = {
    'O','X', 'X','X',
    'X','O', 'O','O',
    'X','X', 'O','X',
    'X','O', 'X','X'
  };
  m = n = 4;
  vector<vector<char> > test(4, vector<char>(4, ' '));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      test[i][j] = a[i][j];
    }
  }
  solve(test);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << test[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
