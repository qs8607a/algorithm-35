// File  : print_phone_word.cc
// Author: zhangshijun(zhangshijun@jike.com)
// Date  : 2012/05/03 01:57:02

#include <iostream>
using namespace std;

char answer[10];

// 
char c[10][10] = {
  "",
  "",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tuv",
  "wxyz"
};

int c_num[10] = {
  0,
  0,
  3,
  3,
  3,
  3,
  3,
  4,
  3,
  4
};


void print_word(char number[], int n) {
  while(true) {
    for (int i = 0; i < n; i++) {
      cout << c[number[i] - '0'][answer[i]];
    }
    cout << endl;
    int k = n - 1;
    while (k >= 0) {
      if(answer[k] < c_num[number[k] - '0'] - 1) {
        answer[k]++;
        break;
      } else {
        answer[k] = 0;
        k--;
      }
    }

    if (k < 0) {
      break;
    }
  }
}

int main() {
  print_word("23", 2);
}









