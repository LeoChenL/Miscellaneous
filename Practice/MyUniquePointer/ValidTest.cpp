#include <string>
#include "ValidTest.h"
/*
Valid functions definition
*/
// Test ctor
bool TestConstructor(){
  std::cout<<"Test ctor"<<std::endl;
  int a=1,b=2;
  int* ptr_a = &a;
  int* ptr_b = &b;
  // Default ctor
  MyUniquePointer<int> int_ptr;
  MyUniquePointer<int> int_ptr_2(ptr_b);
  MyUniquePointer<double> double_ptr;
  MyUniquePointer<std::string> string_ptr;
  if( (int_ptr.get()!=nullptr)||(double_ptr.get()!=nullptr)||
      (string_ptr.get()!=nullptr) ){
    std::cout<<"  Fail Default ctor"<<std::endl;
    return false;
  }
  else{
    std::cout<<"  Pass Default ctor"<<std::endl;
  }
  // Construct from pointer
  MyUniquePointer<int> int_ptr_null(nullptr);
  MyUniquePointer<int> int_ptr_a(ptr_a);
  if( (int_ptr_null.get()!=nullptr)||(*int_ptr_a!=a) ){
    std::cout<<"  Fail ctor(pointer)"<<std::endl;
    return false;
  }
  else{
    std::cout<<"  Pass ctor(pointer)"<<std::endl;
  }
  // Move ctor
  MyUniquePointer<int> int_ptr_move(std::move(int_ptr_2));
  // std::cout<<"  Construction Complete"<<std::endl;
  // Check initialization value
  if( *int_ptr_move!=b ){
    std::cout<<"  Fail Move ctor"<<std::endl;
    return false;
  }
  else{
    std::cout<<"  Pass Move ctor"<<std::endl;
  }
  std::cout<<"  Pass Test ctor"<<std::endl;
  return true;
}

// Test operator=
bool TestOperator(){
  std::cout<<"Test Operator="<<std::endl;
  MyUniquePointer<int> foo;
  MyUniquePointer<int> bar;

  foo = MyUniquePointer<int>(new int(101)); // rvalue
  if( *foo!=101 ){
    std::cout<<"  Fail Move Assignment"<<std::endl;
    return false;
  }
  else{
    bar = std::move(foo);
    if(*bar!=101){
      std::cout<<"  Fail Move Assignment"<<std::endl;
      return false;
    }
    else{
      std::cout<<"  Pass Move Assignment"<<std::endl;
    }
  }
  std::cout<<"  Pass Test Operator="<<std::endl;
  return true;
}

// Test reset
bool TestReset(){
  std::cout<<"Test Reset"<<std::endl;
  MyUniquePointer<int> up;  // empty
  int a=10;
  int* p=&a;

  up.reset(new int);       // takes ownership of pointer
  *up=5;
  up.reset(p);       // deletes managed object, acquires new pointer
  if( *up!=a ){
    std::cout<<"  Fail MyUniquePointer.reset(ptr)"<<std::endl;
    return false;
  }
  else{
    up.reset();               // deletes managed object
    if(up.get()!=nullptr){
      std::cout<<"  Fail MyUniquePointer.reset()"<<std::endl;
      return false;
    }
  }
  std::cout<<"  Pass Test Reset"<<std::endl;
  return true;
}

// Test release
bool TestRelease(){
  std::cout<<"Test Release"<<std::endl;
  MyUniquePointer<int> auto_pointer(new int);
  int* manual_pointer;

  *auto_pointer = 10;
  manual_pointer = auto_pointer.release();
  // (auto_pointer is now empty)
  if(auto_pointer.get()!=nullptr || *manual_pointer!=10){
    std::cout<<"  Fail Release"<<std::endl;
    return false;
  }
  delete manual_pointer;

  std::cout<<"  Pass Test Release"<<std::endl;
  return true;
}
