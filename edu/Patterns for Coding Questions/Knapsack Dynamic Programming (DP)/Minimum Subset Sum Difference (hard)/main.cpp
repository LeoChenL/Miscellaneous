/*
Problem Statement #
Given a set of positive numbers, partition the set into two subsets with minimum difference between their subset sums.

Example 1: #
Input: {1, 2, 3, 9}
Output: 3
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} & {9}.
Example 2: #
Input: {1, 2, 7, 1, 5}
Output: 0
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of number is '0'. Following are the two subsets: {1, 2, 5} & {7, 1}.
Example 3: #
Input: {1, 3, 100, 4}
Output: 92
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of numbers is '92'. Here are the two subsets: {1, 3, 4} & {100}.

Time and Space complexity #
Because of the two recursive calls, the time complexity of the above algorithm
is exponential O(2^n), where ‘n’ represents the total number. The space
complexity is O(n) which is used to store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
 public:
  int canPartition(const vector<int> &num) { return this->canPartitionRecursive(num, 0, 0, 0); }

 private:
  int canPartitionRecursive(const vector<int> &num, int currentIndex, int sum1, int sum2) {
    // base check
    if (currentIndex == num.size()) {
      return abs(sum1 - sum2);
    }

    // recursive call after including the number at the currentIndex in the first set
    int diff1 = canPartitionRecursive(num, currentIndex + 1, sum1 + num[currentIndex], sum2);

    // recursive call after including the number at the currentIndex in the second set
    int diff2 = canPartitionRecursive(num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

    return min(diff1, diff2);
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}
