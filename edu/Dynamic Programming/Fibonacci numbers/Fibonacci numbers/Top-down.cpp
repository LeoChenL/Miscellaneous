using namespace std;

#include <iostream>
#include <vector>

class Fibonacci {

public:
  int CalculateFibonacci(int n) {
    vector<int> dp(n + 1, 0);
    return CalculateFibonacciRecursive(dp, n);
  }

  int CalculateFibonacciRecursive(vector<int> &dp, int n) {
    if (n < 2) {
      return n;
    }
    if (dp[n] == 0) {
      dp[n] = CalculateFibonacciRecursive(dp, n - 1) + CalculateFibonacciRecursive(dp, n - 2);
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  Fibonacci *fib = new Fibonacci();
  cout << "5th Fibonacci is ---> " << fib->CalculateFibonacci(5) << endl;
  cout << "6th Fibonacci is ---> " << fib->CalculateFibonacci(6) << endl;
  cout << "7th Fibonacci is ---> " << fib->CalculateFibonacci(7) << endl;

  delete fib;
}