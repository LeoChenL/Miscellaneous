/*
a time complexity of O(n) but a constant space complexity O(1)
*/

using namespace std;

#include <iostream>

class Fibonacci {

public:
  int CalculateFibonacci(int n) {
    if (n < 2) {
      return n;
    }
    int n1 = 0, n2 = 1, temp;
    for (int i = 2; i <= n; i++) {
      temp = n1 + n2;
      n1 = n2;
      n2 = temp;
    }
    return n2;
  }
};

int main(int argc, char *argv[]) {
  Fibonacci *fib = new Fibonacci();
  cout << "5th Fibonacci is ---> " << fib->CalculateFibonacci(5) << endl;
  cout << "6th Fibonacci is ---> " << fib->CalculateFibonacci(6) << endl;
  cout << "7th Fibonacci is ---> " << fib->CalculateFibonacci(7) << endl;

  delete fib;
}
