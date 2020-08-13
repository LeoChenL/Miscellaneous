// initializerList.cpp

#include <initializer_list>
#include <iostream>
#include <string>

class MyData{
  public:

    MyData(std::string, int){
      std::cout << "MyData(std::string, int)" << std::endl;
    }

    MyData(int, int){
      std::cout << "MyData(int, int)" << std::endl;
    }

    MyData(std::initializer_list<int>){
      std::cout << "MyData(std::initializer_list<int>)" << std::endl;
    }
};

template<typename T>
void printInitializerList(std::initializer_list<T> inList){
  for (auto& e: inList) std::cout << e << " ";
}

int main(){

  std::cout << std::endl;

  // sequence constructor has a higher priority
  // classical constructor serves as a fallback
  MyData{1, 2};

  // invoke the classical constructor explicitly
  MyData(1, 2);

  // use the classical constructor
  MyData{"dummy", 2};

  std::cout << std::endl;

  // print the initializer list of ints
  printInitializerList({1, 2, 3, 4, 5, 6, 7, 8, 9});

  std::cout << std::endl;

  // print the initializer list of strings
  printInitializerList({"Only", "for", "testing", "purpose."});

  std::cout << "\n\n";
}
