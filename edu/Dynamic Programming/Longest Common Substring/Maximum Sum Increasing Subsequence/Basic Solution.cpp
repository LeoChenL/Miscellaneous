/*
Problem Statement #
Given a number sequence, find the increasing subsequence with the highest sum.
Write a method that returns the highest sum.

Example 1:

Input: {4,1,2,6,10,1,12}
Output: 32
Explanation: The increaseing sequence is {4,6,10,12}.
Please note the difference, as the LIS is {1,2,6,10,12} which has a sum of '31'.
Example 2:

Input: {-4,10,3,7,15}
Output: 25
Explanation: The increaseing sequences are {10, 15} and {3,7,15}.


The time complexity of the above algorithm is exponential O(2^n), where ‘n’ is
the lengths of the input array. The space complexity is O(n) which is used to
store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <vector>

class MSIS {

public:
  int findMSIS(const vector<int> &nums) { return findMSISRecursive(nums, 0, -1, 0); }

private:
  int findMSISRecursive(const vector<int> &nums, int currentIndex, int previousIndex, int sum) {
    if (currentIndex == nums.size()) {
      return sum;
    }

    // include nums[currentIndex] if it is larger than the last included number
    int s1 = sum;
    if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
      s1 = findMSISRecursive(nums, currentIndex + 1, currentIndex, sum + nums[currentIndex]);
    }

    // excluding the number at currentIndex
    int s2 = findMSISRecursive(nums, currentIndex + 1, previousIndex, sum);

    return max(s1, s2);
  }
};

int main(int argc, char *argv[]) {
  MSIS *msis = new MSIS();
  vector<int> nums = {4, 1, 2, 6, 10, 1, 12};
  cout << msis->findMSIS(nums) << endl;
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << msis->findMSIS(nums) << endl;

  delete msis;
}
