/*
Problem Statement #
Write a function to calculate the nth Fibonacci number.

Fibonacci numbers are a series of numbers in which each number is the sum of
the two preceding numbers. First few Fibonacci numbers are: 0, 1, 1, 2, 3, 5, 8, …

Mathematically we can define the Fibonacci numbers as:

    Fib(n) = Fib(n-1) + Fib(n-2), for n > 1

    Given that: Fib(0) = 0, and Fib(1) = 1


The time complexity of the above algorithm is exponential O(2^n) as we are
making two recursive calls in the same function. The space complexity is O(n)
which is used to store the recursion stack.
*/

using namespace std;

#include <iostream>

class Fibonacci {

public:
  int CalculateFibonacci(int n) {
    if (n < 2) {
      return n;
    }
    return CalculateFibonacci(n - 1) + CalculateFibonacci(n - 2);
  }
};

int main(int argc, char *argv[]) {
  Fibonacci *fib = new Fibonacci();
  cout << "5th Fibonacci is ---> " << fib->CalculateFibonacci(5) << endl;
  cout << "6th Fibonacci is ---> " << fib->CalculateFibonacci(6) << endl;
  cout << "7th Fibonacci is ---> " << fib->CalculateFibonacci(7) << endl;

  delete fib;
}
