// crtpEquality.cpp

#include <iostream>
#include <string>

template<class Derived>
class Equality{};

template <class Derived>
bool operator == (Equality<Derived> const& op1, Equality<Derived> const & op2){
  Derived const& d1 = static_cast<Derived const&>(op1);
  Derived const& d2 = static_cast<Derived const&>(op2);
  return !(d1 < d2) && !(d2 < d1);
}

template <class Derived>
bool operator != (Equality<Derived> const& op1, Equality<Derived> const & op2){
  Derived const& d1 = static_cast<Derived const&>(op1);
  Derived const& d2 = static_cast<Derived const&>(op2);
  return !(d1 == d2);
}

struct Apple:public Equality<Apple>{
  Apple(int s): size{s}{};
  int size;
};

bool operator < (Apple const& a1, Apple const& a2){
  return a1.size < a2.size;
}

struct Man:public Equality<Man>{
  Man(const std::string& n): name{n}{}
  std::string name;
};

bool operator < (Man const& m1, Man const& m2){
  return m1.name < m2.name;
}


int main(){

  std::cout << std::boolalpha << std::endl;

  Apple apple1{5};
  Apple apple2{10};
  std::cout << "apple1 == apple2: " << (apple1 == apple2) << std::endl;

  Man man1{"grimm"};
  Man man2{"jaud"};
  std::cout << "man1 != man2: " << (man1 != man2) << std::endl;

  std::cout << std::endl;

}

/*
Explanation #
For the classes Apple and Man, we implemented the smaller operator (lines 28 and 37). We will only use the class Man for simplicity. The class Man is public derived (lines 32 - 35) from the class Equality<Man>.

For classes of the kind Equality<Derived>, we implemented the equality (lines 9 - 14) and the inequality operator (lines 16 - 21). The inequality operator uses the equality operator (line 20).

The equality operator relies on the fact that the smaller operator is implemented for Derived (line 13). The equality operator and inequality operator convert their operands: Derived const&: Derived const& d1 = static_cast<Derived const&>(op1).

Now, we can compare Apple and Man for equality and inequality in the main program.
*/
