// unorderedMapHash.cpp
#include <iostream>
#include <ostream>
#include <unordered_map>

struct MyInt{
  MyInt(int v):val(v){}
  bool operator== (const MyInt& other) const {
    return val == other.val;
  }
  int val;
};

struct MyHash{
  std::size_t operator()(MyInt m) const {
    std::hash<int> hashVal;
    return hashVal(m.val);
  }
};

std::ostream& operator << (std::ostream& strm, const MyInt& myIn){
  strm << "MyInt(" << myIn.val << ")";
  return strm;
}

int main(){

  std::cout << std::endl;

  std::hash<int> hashVal;

  // a few hash values
  for ( int i= -2; i <= 1 ; ++i){
    std::cout << "hashVal(" << i << "): " << hashVal(i) << std::endl;
  }

  std::cout << std::endl;

  typedef std::unordered_map<MyInt, int, MyHash> MyIntMap;

  std::cout << "MyIntMap: ";
  MyIntMap myMap{{MyInt(-2), -2}, {MyInt(-1), -1}, {MyInt(0), 0}, {MyInt(1), 1}};

  for(auto m : myMap) std::cout << '{' << m.first << ',' << m.second << '}';

  std::cout << std::endl << std::endl;

}

/*
Explanation #
The class MyInt is a small wrapper for an int.

To use instances of MyInt as a key in an associative container, MyInt must support the hash function and the equal operator.

The class MyHash implements the hash function for the key MyInt by using the hash value for the wrapped int (line 17). Line 34 shows a few hash values for int's. In contrast, the equal operator is implemented inside the class (line 8).

Line 39 defines the type MyIntMap, which uses the hash function MyHash as a template argument.
*/
