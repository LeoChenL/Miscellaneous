#include <iostream>
#include "MyUniquePointer.h"
#include "ValidTest.cpp"
/*
Valid MyUniquePointer class with
some std::unique_ptr example on cplusplus.com
*/

int main() {
  bool T1,T2,T3,T4;
  
  std::cout<<"*******Valid Test Start*******"<<std::endl;
  T1 = TestConstructor();
  T2 = TestOperator();
  T3 = TestReset();
  T4 = TestRelease();

  return 0;
}
