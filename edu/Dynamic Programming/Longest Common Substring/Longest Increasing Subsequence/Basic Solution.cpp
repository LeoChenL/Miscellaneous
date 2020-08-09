/*
Problem Statement #
Given a number sequence, find the length of its Longest Increasing Subsequence
(LIS). In an increasing subsequence, all the elements are in increasing order
(from lowest to highest).

Example 1:

Input: {4,2,3,6,10,1,12}
Output: 5
Explanation: The LIS is {2,3,6,10,12}.
Example 1:

Input: {-4,10,3,7,15}
Output: 4
Explanation: The LIS is {-4,3,7,15}.


The time complexity of the above algorithm is exponential O(2^n), where ‘n’ is
the lengths of the input array. The space complexity is O(n) which is used to
store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <vector>

class LIS {

public:
  int findLISLength(const vector<int> &nums) { return findLISLengthRecursive(nums, 0, -1); }

private:
  int findLISLengthRecursive(const vector<int> &nums, int currentIndex, int previousIndex) {
    if (currentIndex == nums.size()) {
      return 0;
    }

    // include nums[currentIndex] if it is larger than the last included number
    int c1 = 0;
    if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
      c1 = 1 + findLISLengthRecursive(nums, currentIndex + 1, currentIndex);
    }

    // excluding the number at currentIndex
    int c2 = findLISLengthRecursive(nums, currentIndex + 1, previousIndex);

    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LIS *lis = new LIS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lis->findLISLength(nums) << endl;
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << lis->findLISLength(nums) << endl;

  delete lis;
}
