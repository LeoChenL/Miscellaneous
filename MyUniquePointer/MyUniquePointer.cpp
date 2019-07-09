#include <iostream>
#include "MyUniquePointer.h"

int main() {
  int a=11;
  int* ptr_a = &a;
  int* p=nullptr;

  // MyUniquePointer ctor
  MyUniquePointer<int> int_ptr_foo;
  MyUniquePointer<int> int_ptr_bar;
  MyUniquePointer<int> int_ptr_a(ptr_a);
  std::cout<<"ptr created"<<std::endl;

  int_ptr_foo = MyUniquePointer<int>(new int(10));
  int_ptr_bar = std::move(int_ptr_foo);
  p = int_ptr_bar.get();
  *p = 20;
  p = nullptr;

  int_ptr_foo = MyUniquePointer<int>(new int(30));
  p = int_ptr_foo.release();
  *p = 40;


  std::cout << "foo: ";
  if (int_ptr_foo.get()!=nullptr) std::cout << *int_ptr_foo << '\n'; else std::cout << "(null)\n";

  std::cout << "bar: ";
  if (int_ptr_bar.get()!=nullptr) std::cout << *int_ptr_bar << '\n'; else std::cout << "(null)\n";

  std::cout << "p: ";
  if (p!=nullptr) std::cout << *p << '\n'; else std::cout << "(null)\n";
  std::cout << '\n';

  delete p;

  return 0;
}
