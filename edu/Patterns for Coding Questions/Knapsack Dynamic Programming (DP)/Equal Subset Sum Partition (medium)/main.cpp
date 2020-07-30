/*
Problem Statement #
Given a set of positive numbers, find if we can partition it into two subsets
such that the sum of elements in both subsets is equal.

Example 1:

Input: {1, 2, 3, 4}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum:
{1, 4} & {2, 3}
Example 2:

Input: {1, 1, 3, 4, 7}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum:
{1, 3, 4} & {1, 7}
Example 3:

Input: {2, 3, 4, 6}
Output: False
Explanation: The given set cannot be partitioned into two subsets with equal sum.


Time and Space complexity #
The time complexity of the above algorithm is exponential O(2^n), where ‘n’
represents the total number. The space complexity is O(n), which will be 
used to store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
 public:
  bool canPartition(const vector<int> &num) {
    int sum = 0;
    for (int i = 0; i < num.size(); i++) {
      sum += num[i];
    }

    // if 'sum' is a an odd number, we can't have two subsets with equal sum
    if (sum % 2 != 0) {
      return false;
    }

    return this->canPartitionRecursive(num, sum / 2, 0);
  }

 private:
  bool canPartitionRecursive(const vector<int> &num, int sum, int currentIndex) {
    // base check
    if (sum == 0) {
      return true;
    }

    if (num.empty() || currentIndex >= num.size()) {
      return false;
    }

    // recursive call after choosing the number at the currentIndex
    // if the number at currentIndex exceeds the sum, we shouldn't process this
    if (num[currentIndex] <= sum) {
      if (canPartitionRecursive(num, sum - num[currentIndex], currentIndex + 1)) {
        return true;
      }
    }

    // recursive call after excluding the number at the currentIndex
    return canPartitionRecursive(num, sum, currentIndex + 1);
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartition(num) << endl;
}
