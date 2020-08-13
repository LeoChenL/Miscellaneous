// nullptr.cpp
#include <iostream>
#include <string>

std::string overloadTest(char*){
  return "char*";
}

std::string overloadTest(int){
  return "int";
}

std::string overloadTest(long int){
  return "long int";
}

std::string test2(char*){
  return "char*";
}

int main(){

  std::cout << std::endl;

  int* pi = nullptr;    // OK
  // int i= nullptr;       // cannot convert ‘std::nullptr_t’ to ‘int’
  bool b{nullptr};      // OK. b is false.

  std::cout << std::boolalpha << "b: "  << b << std::endl;

  // calls int
  std::cout << "overloadTest(0) = " <<  overloadTest(0) << std::endl;

  // calls char*
  std::cout<< "overloadTest(static_cast<char*>(0))= " << overloadTest(static_cast<char*>(0)) << std::endl;
  std::cout<< "test2(0)= " << test2(0) << std::endl;

  // calls char*
  std::cout << "overloadTest(nullptr)= " <<  overloadTest(nullptr)<< std::endl;

  // call of overloaded ‘overloadTest(NULL)’ is ambiguous
  // std::cout << "overloadTest(NULL)= " << overloadTest(NULL) << std::endl;

  std::cout << std::endl;

}
