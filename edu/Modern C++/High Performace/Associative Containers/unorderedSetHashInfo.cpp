// unorderedSetHashInfo.cpp
#include <iostream>
#include <random>
#include <unordered_set>

void getInfo(const std::unordered_set<int>& mySet){

  std::cout << "mySet.bucket_count(): " << mySet.bucket_count() << std::endl;
  std::cout << "mySet.load_factor(): " << mySet.load_factor() << std::endl;

}

void fillMySet(std::unordered_set<int>& h, int n){

  std::random_device seed;
  // default generator
  std::mt19937 engine(seed());
  // get random numbers 0 - 1000
  std::uniform_int_distribution<> uniformDist(0, 1000);

  for (int i = 1; i<= n; ++i){
    h.insert(uniformDist(engine));
  }

}

int main(){

  std::cout << std::endl;

  std::unordered_set<int> mySet;
  std::cout << "mySet.max_load_factor(): " << mySet.max_load_factor() << std::endl;

  std::cout << std::endl;

  getInfo(mySet);

  std::cout << std::endl;

  // only to be sure
  mySet.insert(500);
  // get the bucket of 500
  std::cout << "mySet.bucket(500): " << mySet.bucket(500) << std::endl;

  std::cout << std::endl;

  // add 100 elements
  fillMySet(mySet, 100);
  getInfo(mySet);

  std::cout << std::endl;

  std::cout << "---------------" << std::endl;

  auto numBuck = mySet.bucket_count();

  std::cout << "mySet.bucket_count(): " << mySet.bucket_count();

  std::cout << "\n\n\n";

  for (std::size_t i = 0; i < numBuck; ++i){
      std::cout << "mySet.bucket_size(" << i << "): " << mySet.bucket_size(i) << std::endl;
      for (auto it = mySet.begin(i); it != mySet.end(i); ++it) std::cout << *it <<  " ";
      std::cout << std::endl;
   }

  std::cout << " ---------------"  << "\n\n";


  // at least 500 buckets
  std::cout << "mySet.rehash(500): " << std::endl;
  mySet.rehash(500);

  std::cout << std::endl;

  getInfo(mySet);

  std::cout << std::endl;

  // get the bucket of 500
  std::cout << "mySet.bucket(500): " << mySet.bucket(500) << std::endl;

  numBuck = mySet.bucket_count();
  std::cout << "mySet.bucket_count(): " << mySet.bucket_count() << std::endl;

  std::cout << std::endl;

}

/*
Explanation #
The example shows the internal working of std::unordered_set. The behavior would be similar for each other unordered associative container.

The function getInfo (lines 6 - 11) is a convenience function which returns both the number of buckets and the load factor for a given std::unordered_set.

The program shows the max_load_factor, which returns the value when a rehashing would occur.

In line 41, the program inserts 500 into the mySet, and line 43 returns the bucket in which 500 is stored.

In line 48, the function call fillMySet causes 100 elements between 0 and 1000 to be added to mySet.

Due to the number of buckets numBuck, it is possible to show how many and which elements are inside each bucket. This occurs in lines 61 - 65.

A call mySet.rehash(500) in line 71 creates at least 500 buckets for mySet, meaning that all elements are distributed in new buckets.
*/
