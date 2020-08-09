/*
Introduction #
Given an infinite supply of ‘n’ coin denominations and a total money amount,
we are asked to find the total number of distinct ways to make up that amount.

Example:

Denominations: {1,2,3}
Total amount: 5
Output: 5
Explanation: There are five ways to make the change for '5', here are those ways:
  1. {1,1,1,1,1}
  2. {1,1,1,2}
  3. {1,2,2}
  4. {1,1,3}
  5. {2,3}
Problem Statement #
Given a number array to represent different coin denominations and a total
amount ‘T’, we need to find all the different ways to make a change for ‘T’
with the given coin denominations. We can assume an infinite supply of coins,
therefore, each coin can be chosen multiple times.


The time complexity of the above algorithm is exponential O(2^{C+T}), where ‘C’
represents total coin denominations and ‘T’ is the total amount that we want to
make change. The space complexity will be O(C+T).
*/

using namespace std;

#include <iostream>
#include <vector>

class CoinChange {
public:
  int countChange(const vector<int> &denominations, int total) {
    return this->countChangeRecursive(denominations, total, 0);
  }

private:
  int countChangeRecursive(const vector<int> &denominations, int total, int currentIndex) {
    // base checks
    if (total == 0) {
      return 1;
    }
    if (denominations.empty() || currentIndex >= denominations.size()) {
      return 0;
    }
    // recursive call after selecting the coin at the currentIndex
    // if the coin at currentIndex exceeds the total, we shouldn't process this
    int sum1 = 0;
    if (denominations[currentIndex] <= total) {
      sum1 = countChangeRecursive(denominations, total - denominations[currentIndex], currentIndex);
    }
    // recursive call after excluding the coin at the currentIndex
    int sum2 = countChangeRecursive(denominations, total, currentIndex + 1);
    return sum1 + sum2;
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;

  delete cc;
}
