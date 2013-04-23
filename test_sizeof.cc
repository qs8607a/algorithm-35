/***************************************************************************
 * 
 * Copyright (c) 2012 jike.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file test_sizeof.cc
 * @author zhangshijun(zhangshijun@jike.com)
 * @date 2012/06/05 09:07:42
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

int main(){
  char * lang[] = {"abc", "abc", "abc","1gc","fdsfds"};
  cout << sizeof(lang);
  return 0;
}



















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
