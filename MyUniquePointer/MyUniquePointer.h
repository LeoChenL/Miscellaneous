#INNDEF MYUNIQUEPOINTER_H
#DEFINE MYUNIQUEPOINTER_H
/*
Practice
To achieve my unique poiter class with template
*/

template <typename T>
class MyUniquePointer {
private:
  T* ptr_;
public:
  // ctor
  // MyUniquePointer():ptr_(nullptr){}
  MyUniquePointer(T* obj_ptr=nullptr):ptr_(obj_ptr){}

  MyUniquePointer(const T& obj){
    ptr_ = &obj;
  }

  // Delete copy ctor and assignment
  MyUniquePointer(const MyUniquePointer<T>& ptr) = delete; // Do not allow two pointer pointing to the same object
  MyUniquePointer& operator=(MyUniquePointer<T>& ptr) = delete; // return value is reference to achieve a=b=c=0

  // Move ctor and assignment
  MyUniquePointer(MyUniquePointer<T>&& ptr){
    reset(ptr.release());
    std::cout<<"Move ctor"<<std::endl;
  }
  MyUniquePointer& operator=(MyUniquePointer<T>&& ptr){
    reset(ptr.release());
    std::cout<<"Move assignment"<<std::endl;
    return *this;
  }

  ~MyUniquePointer(){
    // Cannot delete a nullptr
    if(ptr_ != nullptr){
      delete ptr_;
    }
  }

  /*
  Method release()
  Releases ownership of its stored pointer,
  by returning its value and replacing it with a null pointer.
  */
  T* release(){
    T* ptr_tmp;
    ptr_tmp = ptr_;
    ptr_ = nullptr;
    return ptr_tmp;
  }

  /*
  Method reset()
  Destroys the object currently managed by the unique_ptr (if any)
  and takes ownership of p.
  */
  void reset(){
    if(ptr_ != nullptr){
      delete ptr_;
    }
    ptr_ = nullptr;
  }

  void reset(T* obj_ptr){
    if(ptr_ != nullptr){
      delete ptr_;
    }
    ptr_ = obj_ptr;
  }

  /*
  Method get
  Returns the stored pointer.
  The stored pointer points to the object managed by the unique_ptr,
  if any, or to nullptr if the unique_ptr is empty.
  */
  T* get(){
    return ptr_;
  }

  /*
  Method operator->
  Dereference object member
  Returns a pointer to the managed object in order to access
  one of its members.
  e.g.
  p->m = 10  = (p.operator->())->m = 10
  */
  T* operator->(){
    return ptr_;
  }

  /*
  Method operator*
  Dereference object
  Returns a reference to the managed object.
  */
  T& operator*(){
    return *ptr_; // Note, return reference value, *ptr_ still exists after this func
  }
}; // end class MyUniquePointer



#ENDIF // END MYUNIQUEPOINTER_H
