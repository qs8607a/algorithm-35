// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : StringToInteger.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/21 22:31:24

#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

#define INT_MAX 2147483647;
#define INT_MIN -2147483648;


int atoi(const char *str) {
  if (str == NULL) {
    return 0;
  }
  bool has_flag = true, has_digit = false;
  int factor = 1, value = 0, i = 0;
  while (i < strlen(str)) {
    if (isdigit(str[i])) {
      has_digit = true;
      if ((value + (str[i] - '0') / 10.0) >= 214748364.7
          && factor == 1) {
        return INT_MAX;
      }
      if ((value + (str[i] - '0') / 10.0) >= 214748364.8
          && factor == -1) {
        return INT_MIN;
      }
      int tmp = value * 10 + str[i] - '0';
      value = tmp;
    } else if (str[i] == '-' && has_flag && !has_digit) {
      has_flag = false;
      factor = -1;
    } else if (str[i] == '+' && has_flag && !has_digit) {
      has_flag = false;
      factor = 1;
    } else if (str[i] != ' ' || (str[i] == ' ' && (!has_flag || has_digit))){
      // cout <<  << endl;
      return factor * value;
    }
    i++;
  }
  return factor * value;
}

int main() {
  // char buffer[] = "-123";
  // cout << atoi(buffer) << endl;
  // char buffer2[] = "-2147483647";
  // cout << atoi(buffer2) << endl;
  // char buffer3[] = " +1 2 3";
  // cout << atoi(buffer3) << endl;
  // char buffer4[] = " 1- 2 3";
  // cout << atoi(buffer4) << endl;
  char buffer5[] = "+10523538441s";
  cout << atoi(buffer5) << endl;
  char buffer6[] = " +105 1s";
  cout << atoi(buffer6) << endl;

}










