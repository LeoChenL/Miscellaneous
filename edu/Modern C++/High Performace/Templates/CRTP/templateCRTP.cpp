// templateCRTP.cpp

#include <iostream>

template <typename Derived>
struct Base{
  void interface(){
    static_cast<Derived*>(this)->implementation();
  }

  void implementation(){
    std::cout << "Implementation Base" << std::endl;
  }
};

struct Derived1: Base<Derived1>{
  void implementation(){
    std::cout << "Implementation Derived1" << std::endl;
  }
};

struct Derived2: Base<Derived2>{
  void implementation(){
    std::cout << "Implementation Derived2" << std::endl;
  }
};

struct Derived3: Base<Derived3>{};

template <typename T>
void execute(T& base){
    base.interface();
}


int main(){

  std::cout << std::endl;

  Derived1 d1;
  execute(d1);

  Derived2 d2;
  execute(d2);

  Derived3 d3;
  execute(d3);

  std::cout << std::endl;

}

/*
Explanation #
*In the function template execute (lines 30-33), we used static polymorphism.

On each argument, we invoked the base method base.interface. The method Base::interface in lines 7 - 9 is the key point of the CRTP idiom. The methods dispatch to the implementation of the derived class: static_cast<Derived*>(this)->implementation().This is possible since the method is instantiated when called.

Now, the derived classes Derived1, Derived2, and Derived3 are fully defined. Therefore, the method Base::interface can use the details of its derived classes. Especially interesting is the method Base::implementation (lines 11 - 13).

This method plays the role of a default implementation of the static polymorphism for the class Derived3 (line 28).


*/
