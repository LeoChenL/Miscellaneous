// templateClassTemplateInheritance.cpp

#include <iostream>

template <typename T>
class Base{
public:
  void func1() const {
    std::cout << "func1()" << std::endl;
  }
  void func2() const {
    std::cout << "func2()" << std::endl;
  }
  void func3() const {
    std::cout << "func3()" << std::endl;
  }
};

template <typename T>
class Derived: public Base<T>{
public:
  using Base<T>::func2;

  void callAllBaseFunctions(){
    this->func1();
    func2();
    Base<T>::func3();
  }
};

int main(){
  std::cout << std::endl;

  Derived<int> derived;
  derived.callAllBaseFunctions();

  std::cout << std::endl;
}

/*
Explanation #
We have implemented a Base and Derived classes. Derived is publicly inherited from Base and may use callAllBaseFunctions in line 24, the methods func1, func2, and func3 from the Base class.

Make the name dependent: The call this->func1 in line 25 is dependent. The name lookup will consider in this case, all base classes.

Introduce the name into the current scope: The expression using Base<T>::func2 (line 22) introduces func2 into the current scope.

Call the name fully qualified: Calling func3 fully qualified (line 27) will break a virtual dispatch and may cause new surprises.

We created a Derived class object named derived. By using this object, we can access the base class functions by calling method callAllBaseFunctions.
*/
