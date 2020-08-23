/*
Practice
To achieve my shared poiter class with template
*/

#include <iostream>
using namespace std;


template<typename T>
class MySharePtr{
private:
  T *_ptr;
  int *_count;

public:
  // Constructor
  MySharePtr(T *ptr=nullptr); // MySharePtr<int> sp(new int(2))
  MySharePtr(const MySharePtr<T> &sp); // MySharePtr<int> sp2(sp1)
  MySharePtr<T>& operator=(const MySharePtr<T> &rhs); // sp2 = sp1
  // Deconstructor
  ~MySharePtr();

  T operator*();
  T* operator->();
  T* operator+(int i);
  bool operator==(const MySharePtr &sp);
  bool operator!=(const MySharePtr &sp);
  int getcount();
};

// Constructor
template<typename T>
MySharePtr<T>::MySharePtr(T *ptr) {
  // default param not in decleration
  _ptr = ptr;
  try{
    _count = new int(1);
  }
  catch (...) {
    _ptr = nullptr;
    delete _count;
    _count = nullptr;
  }
}

template<typename T>
MySharePtr<T>::MySharePtr(const MySharePtr<T> &sp) {
  this->_ptr = sp._ptr;
  _count = sp._count;
  if ( _ptr!=nullptr ) {
    ++(*_count);
  }
}

template<typename T>
MySharePtr<T>& MySharePtr<T>::operator=(const MySharePtr<T> &rhs) {
  if ( this!=&rhs ) {
    // avoid assigning itself
    ++(*rhs._count);
    --(*_count);
    if ( _count == 0 ) {
      delete _ptr;
      delete _count;
      _ptr = nullptr;
      _count = nullptr;
    }
    _ptr = rhs._ptr;
    _count = rhs._count;
  }

  return *this;
}

// Destructor
template<typename T>
MySharePtr<T>::~MySharePtr() {
  cout<<"MySharePtr Destructor"<<endl;
  --(*_count);
  cout<<"use count:"<<*_count<<endl;
  if ( *_count == 0 ) {
    cout<<"Delete ptr and count"<<endl;
    delete _ptr;
    delete _count;
    _ptr = nullptr;
    _count = nullptr;
  }
}

// Member function
template<typename T>
T MySharePtr<T>::operator*() {
  return *_ptr;
}

template<typename T>
T* MySharePtr<T>::operator->() {
  return _ptr;
}

template<typename T>
T* MySharePtr<T>::operator+(int i) {
  T *tmp = _ptr + i;
  return tmp;
}

template<typename T>
int MySharePtr<T>::getcount() {
  return *_count;
}

template<typename T>
bool MySharePtr<T>::operator==(const MySharePtr &sp) {
  return _ptr==sp._ptr;
}

template<typename T>
bool MySharePtr<T>::operator!=(const MySharePtr &sp) {
  return _ptr!=sp._ptr;
}


int main(int argc, char const *argv[]) {
  MySharePtr<int> sptr = new int(2);
  cout<<"val: "<<*sptr<<endl;
  cout<<"use count: "<<sptr.getcount()<<endl;
  MySharePtr<int> sptr2 = sptr; // copy constructor
  cout<<"use count: "<<sptr2.getcount()<<endl;
  MySharePtr<int> sptr3;
  sptr3 = sptr; // assignment
  cout<<"use count: "<<sptr3.getcount()<<endl;
  return 0;
}
