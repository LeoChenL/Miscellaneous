/*
Introduction #
Given an infinite supply of ‘n’ coin denominations and a total money amount, we
are asked to find the minimum number of coins needed to make up that amount.

Example 1:

Denominations: {1,2,3}
Total amount: 5
Output: 2
Explanation: We need minimum of two coins {2,3} to make a total of '5'
Example 2:

Denominations: {1,2,3}
Total amount: 11
Output: 4
Explanation: We need minimum four coins {2,3,3,3} to make a total of '11'
Problem Statement #
Given a number array to represent different coin denominations and a total
amount ‘T’, we need to find the minimum number of coins needed to make change
for ‘T’. We can assume an infinite supply of coins, therefore, each coin can be
chosen multiple times.


The time complexity of the above algorithm is exponential O(2^{C+T}), where ‘C’
represents total coin denominations and ‘T’ is the total amount that we want to
make change. The space complexity will be O(C+T).
*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CoinChange {

public:
  int countChange(const vector<int> &denominations, int total) {
    int result = this->countChangeRecursive(denominations, total, 0);
    return (result == numeric_limits<int>::max() ? -1 : result);
  }

private:
  int countChangeRecursive(const vector<int> &denominations, int total, int currentIndex) {
    // base check
    if (total == 0) {
      return 0;
    }

    if (denominations.empty() || currentIndex >= denominations.size()) {
      return numeric_limits<int>::max();
    }

    // recursive call after selecting the coin at the currentIndex
    // if the coin at currentIndex exceeds the total, we shouldn't process this
    int count1 = numeric_limits<int>::max();
    if (denominations[currentIndex] <= total) {
      int res =
          countChangeRecursive(denominations, total - denominations[currentIndex], currentIndex);
      if (res != numeric_limits<int>::max()) {
        count1 = res + 1;
      }
    }

    // recursive call after excluding the coin at the currentIndex
    int count2 = countChangeRecursive(denominations, total, currentIndex + 1);

    return min(count1, count2);
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;
  cout << cc->countChange(denominations, 11) << endl;
  cout << cc->countChange(denominations, 7) << endl;
  denominations = vector<int>{3, 5};
  cout << cc->countChange(denominations, 7) << endl;

  delete cc;
}
