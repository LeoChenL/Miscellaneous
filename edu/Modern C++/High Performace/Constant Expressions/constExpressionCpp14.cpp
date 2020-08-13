//constExpressionCpp14.cpp
#include <iostream>

constexpr int gcd(int a, int b){
  while (b != 0){
    auto t= b;
    b= a % b;
    a= t;
  }
  return a;
}

int main(){

  constexpr auto res= gcd(100, 10);
  std::cout << "gcd(100, 10) " << res << std::endl;

}

/*
Explanation #
The difference between ordinary functions and constexpr functions in C++14 is
minimal. It is quite easy to implement the gcd algorithm in C++14 as a constexpr
function.

We have defined res as a constexpr variable, and its type is automatically
determined by auto.

Note that we cannot use a non-constant value as input arguments for the gcd
function.
*/
