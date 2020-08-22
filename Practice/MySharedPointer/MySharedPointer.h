#ifndef MYSHAREDPOINTER
#define MYSHAREDPOINTER
/*
Practice
To achieve my shared poiter class with template
*/

template<typename T>
class MySharePointer{
private:
  T *ptr;
  int *use_count;

public:
  // Constructor
  MySharePointer(T *p); // MySharePointer<int> sp(new int(2))
  MySharePointer(const MySharePointer<T> &sp); // MySharePointer<int> sp2(sp1)
  MySharePointer<T>& operator=(const MySharePointer<T> &rhs); // sp2 = sp1
  // Deconstructor
  ~MySharePointer();

  T operator*();
  T* operator->();
  T* operator+(int i);
  int operator-(MySharePointer<T> &sp1, MySharePointer<T> &sp2);
  int getcount();
};

#endif
