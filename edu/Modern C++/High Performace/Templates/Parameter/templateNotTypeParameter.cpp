// templateNotTypeParameter.cpp

#include <cstddef>
#include <iostream>
#include <typeinfo>

template <char c>
class AcceptChar{
public:
  AcceptChar(){
    std::cout << "AcceptChar: "  << typeid(c).name() << std::endl;
  }
};

template < int(*func)(int) >
class AcceptFunction{
public:
  AcceptFunction(){
    std::cout << "AcceptFunction: "  << typeid(func).name() << std::endl;
  }
};

template < int(&arr)[5] >
class AcceptReference{
public:
  AcceptReference(){
    std::cout << "AcceptReference: " << typeid(arr).name() << std::endl;
  }
};

template < std::nullptr_t N >
class AcceptNullptr{
public:
  AcceptNullptr(){
    std::cout << "AcceptNullpt: " << typeid(N).name() << std::endl;
  }
};

int myFunc(int){ return 2011; };
int arr[5];

int main(){

  std::cout << std::endl;

  AcceptChar<'c'> acceptChar;
  AcceptFunction< myFunc> acceptFunction;
  AcceptReference< arr > acceptReference;
  AcceptNullptr< nullptr > acceptNullptr;

  std::cout << std::endl;

}

/*
Explanation #
We have created four different class templates, including AcceptChar,
AcceptFunction, AcceptReference, and AcceptNull in lines 8, 16, 24, and 32.

Each class template accepts a different non-type. To verify all types, we
declared a character variable, a reference to an array, a function, and nullptr
in lines (46 – 49). We identify their type using the keyword typeid in lines 11, 19, 27, and 35.
*/
