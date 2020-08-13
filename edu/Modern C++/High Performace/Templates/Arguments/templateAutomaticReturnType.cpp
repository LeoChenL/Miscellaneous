// templateAutomaticReturnType.cpp

#include <iostream>
#include <typeinfo>

template<typename T1, typename T2>
auto add(T1 first, T2 second) -> decltype(first + second){
    return first + second;
}

int main(){

  std::cout << std::endl;

  std::cout << "add(1, 1)= " << add(1, 1) << std::endl;
  std::cout << "typeid(add(1, 1)).name()= " << typeid(add(1, 1)).name() << std::endl;

  std::cout << std::endl;

  std::cout << "add(1, 2.1)= " << add(1, 2.1) << std::endl;
  std::cout << "typeid(add(1, 2.1)).name()= " << typeid(add(1, 2.1)).name() << std::endl;

  std::cout << std::endl;

  std::cout << "add(1000LL, 5)= " << add(1000LL, 5) << std::endl;
  std::cout << "typeid(add(1000LL, 5)).name()= " << typeid(add(1000LL, 5)).name() << std::endl;

  std::cout << std::endl;

}

/*
Explanation #
The function template add takes two type parameters and deduces the return type.
The lines 16, 21, and 26 shows a string representation n of the types, and the
compiler deduces with the help of decltype.

Line 16 is an int, line 21 is a double. Line 26 is a long long int.

The GCC displaces a long long int as x.
*/
