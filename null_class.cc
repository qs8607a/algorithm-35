/***************************************************************************
 * 
 * Copyright (c) 2012 jike.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file null_class.cc
 * @author zhangshijun(zhangshijun@jike.com)
 * @date 2012/06/13 14:13:28
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

class ClassA {

};
class ClassB {
 private:
  int b;
};
class ClassC : public ClassA {

};
class ClassD : public ClassB {

};
class ClassE {
 public:
  int GetReturnValue() {
    return 0;
  }
};
struct StructA {

};

int main() {
  cout << "ClassA " << sizeof(ClassA) << endl;
  cout << "ClassB " << sizeof(ClassB) << endl;
  cout << "ClassC " << sizeof(ClassC) << endl;
  cout << "ClassD " << sizeof(ClassD) << endl;
  cout << "ClassE " << sizeof(ClassE) << endl;
  cout << "StructA " << sizeof(StructA) << endl;
}




















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
