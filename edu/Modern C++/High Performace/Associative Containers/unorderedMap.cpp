//unorderedMap.cpp
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

int main(){

  std::cout << std::endl;

  // using the C++ map
  std::map<std::string, int> m { {"Dijkstra", 1972}, {"Scott", 1976}, {"Wilkes", 1967}, {"Hamming", 1968} };
  for(auto p : m) std::cout << '{' << p.first << ", " << p.second << '}';
  std::cout << std::endl;
  std::cout << "m[Scott]: " << m["Scott"] << std::endl;
  m["Ritchie"] = 1983;
  m["Scott"]= 1988;
  for(auto p : m) std::cout << '{' << p.first << ", " << p.second << '}';

  std::cout << "\n\n";

  // using the C++11 unordered_map
  std::unordered_map<std::string, int> um { {"Dijkstra", 1972}, {"Scott", 1976}, {"Wilkes", 1967}, {"Hamming", 1968} };
  for(auto p: um) std::cout << '{' << p.first << ", " << p.second << '}';
  std::cout << std::endl;
  std::cout << "um[Scott]: " << um["Scott"] << std::endl;
  um["Ritchie"] = 1983;
  um["Scott"]= 1988;
  for(auto p : um) std::cout << '{' << p.first << ", " << p.second << '}';

  std::cout << std::endl;

  std::cout << std::endl;
}
