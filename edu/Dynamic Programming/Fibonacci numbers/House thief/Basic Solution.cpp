/*
There are ‘n’ houses built in a line. A thief wants to steal maximum possible
money from these houses. The only restriction the thief has is that he can’t
steal from two consecutive houses, as that would alert the security system.
How should the thief maximize his stealing?

Problem Statement #
Given a number array representing the wealth of ‘n’ houses, determine the
maximum amount of money the thief can steal without alerting the security system.

Example 1:

Input: {2, 5, 1, 3, 6, 2, 4}
Output: 15
Explanation: The thief should steal from houses 5 + 6 + 4
Example 2:

Input: {2, 10, 14, 8, 1}
Output: 18
Explanation: The thief should steal from houses 10 + 8


The time complexity of the above algorithm is exponential O(2^n). The space
complexity is O(n) which is used to store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <vector>

class HouseThief {
public:
  int findMaxSteal(const vector<int> &wealth) { return findMaxStealRecursive(wealth, 0); }

private:
  int findMaxStealRecursive(const vector<int> &wealth, int currentIndex) {
    if (currentIndex >= wealth.size()) {
      return 0;
    }
    // steal from current house and skip one to steal next
    int stealCurrent = wealth[currentIndex] + findMaxStealRecursive(wealth, currentIndex + 2);
    // skip current house to steel from the adjacent house
    int skipCurrent = findMaxStealRecursive(wealth, currentIndex + 1);
    return max(stealCurrent, skipCurrent);
  }
};

int main(int argc, char *argv[]) {
  HouseThief *ht = new HouseThief();
  vector<int> wealth = {2, 5, 1, 3, 6, 2, 4};
  cout << ht->findMaxSteal(wealth) << endl;
  wealth = vector<int>{2, 10, 14, 8, 1};
  cout << ht->findMaxSteal(wealth) << endl;

  delete ht;
}
