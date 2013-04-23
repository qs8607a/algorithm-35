// Copyright 2012 Jike Inc. All Rights Reserved.
// File  : word_ladder.cc
// Author: Shijun Zhang(zhangshijun@jike.com)
// Date  : 2013/04/17 14:49:24




#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

int ladderLength(string start, string end, set<string> &dict) {
  if (start.size() != end.size() || dict.size() == 0) {
    return 0;
  }
  int length = 1;
  queue<string> pop_list, push_list;
  pop_list.push(start);
  while (dict.size() >= 0 && pop_list.size() > 0) {
    while (pop_list.size() > 0) {
      string tmp = pop_list.front();
      for (int i = 0; i < tmp.size(); i++) {
        for (char j = 'a'; j <= 'z'; j++) {
          tmp = pop_list.front();
          if (tmp[i] == j) {
            continue;
          }
          tmp[i] = j;
          if (tmp == end) {
            return length + 1;
          }
          if (dict.count(tmp) > 0) {
            push_list.push(tmp);
            dict.erase(tmp);
            cout << tmp << " ";
          }
        }
      }
      pop_list.pop();
    }
    length++;
    swap(pop_list, push_list);
  }
  return 0;
}

int main() {
  string start = "hit";
  string end = "cog";
  set<string> dict;
  dict.insert("hot");
  dict.insert("dot");
  dict.insert("dog");
  dict.insert("lot");
  dict.insert("log");
  cout <<ladderLength(start, end, dict) << endl;
}
