#include <iostream>
##include "MySharePointer.h"

// Constructor
template<typename T>
MySharePointer<T>::MySharePointer(T *p) {
  ptr = p;
  try{
    use_count = new int(1);
  }
  catch (...) {
    ptr = nullptr;
    delete use_count;
    use_count = nullptr;
  }
}

template<typename T>
MySharePointer<T>::MySharePointer(const MySharePointer<T> &sp) {
  this->ptr = sp.ptr;
  use_count = sp.use_count;
  ++(*use_count);
}

template<typename T>
MySharePointer<T>::MySharePointer<T>& operator=(const MySharePointer<T> &rhs) {
  ++(*rhs.use_count);
  --(*use_count);
  if ( use_count == 0 ) {
    delete ptr;
    ptr = nullptr;
    delete use_count;
    use_count = nullptr;
  }
  ptr = rhs.ptr;
  *use_count = *(rhs.use_count);
  return *this;
}

// Deconstructor
template<typename T>
MySharePointer<T>::~MySharePointer() {
  getcount();
  delete ptr;
  ptr = nullptr;
  delete use_count;
  use_count = nullptr;
}

// Member function
template<typename T>
T MySharePointer<T>::operator*() {
  return *ptr;
}

template<typename T>
T* MySharePointer<T>::operator->() {
  return ptr;
}

template<typename T>
T* MySharePointer<T>::operator+(int i) {
  T *tmp = ptr + i;
  return tmp;
}

template<typename T>
int MySharePointer<T>::operator-(MySharePointer<T> &sp1, MySharePointer<T> &sp2) {
  return sp1.ptr - sp2.ptr;
}

template<typename T>
int MySharePointer::getcount() {
  return *use_count;
}
