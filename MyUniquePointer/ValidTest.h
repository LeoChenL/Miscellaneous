#ifndef VALIDTEST_H
#define VALIDTEST_H
/*
To valid the MyUniquePointer class can achieve
the same functions as std::unique_ptr
*/

// Test ctor
/*
Default ctor
ctor(ptr)
Move ctor
*/
bool TestConstructor();

// Test operator=
/*
Move assignment
*/
bool TestOperator();

// Test reset
/*
reset(ptr)
reset()
*/
bool TestReset();

// Test release
/*
ptr_new = ptr_org.release();
After release the original Pointer = nullptr &&
the new pointer pointing to the obj
*/
bool TestRelease();

#endif // END VALIDTEST_H
