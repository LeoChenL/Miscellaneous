#include <iostream>
#include <stdio.h>

using namespace std;

class ArrayStack {
// Implement stack using arrary
public:
  int s[101];
  int top = -1;

  void push(int x) {
    cout << "Push in the stack" << endl;
    if ( top == 100 ) {
      cout << "Error: Over size!" << endl;
      return;
    }
    top++;
    s[top] = x;
    print_stack();
    cout << endl;
  }

  void pop() {
    cout << "Pop the top of the stack" << endl;
    if ( top == -1 ) {
      cout << "Error: No element!" << endl;
      return;
    }
    top--;
    print_stack();
    cout << endl;
  }

  void print_stack() {
    for (int i=0; i<=top; ++i) {
      cout << s[i] << ' ';
    }
    cout << endl;
  }
};//end class stack

int main(int argc, char const *argv[]) {
  ArrayStack astk;
  astk.push(1);
  astk.push(2);
  astk.push(3);
  astk.pop();
  astk.pop();
  return 0;
}
