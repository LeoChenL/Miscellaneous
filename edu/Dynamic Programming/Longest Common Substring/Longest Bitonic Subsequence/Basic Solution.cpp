/*
Problem Statement #
Given a number sequence, find the length of its Longest Bitonic Subsequence (LBS).
A subsequence is considered bitonic if it is monotonically increasing and then
monotonically decreasing.

Example 1:

Input: {4,2,3,6,10,1,12}
Output: 5
Explanation: The LBS is {2,3,6,10,1}.
Example 2:

Input: {4,2,5,9,7,6,10,3,1}
Output: 7
Explanation: The LBS is {4,5,9,7,6,3,1}.


The time complexity of the above algorithm is exponential O(2^n), where ‘n’ is
the lengths of the input array. The space complexity is O(n) which is used to
store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <vector>

class LBS {

public:
  int findLBSLength(const vector<int> &nums) {
    int maxLength = 0;
    for (int i = 0; i < nums.size(); i++) {
      int c1 = findLDSLength(nums, i, -1);
      int c2 = findLDSLengthRev(nums, i, -1);
      maxLength = max(maxLength, c1 + c2 - 1);
    }
    return maxLength;
  }

private:
  // find the longest decreasing subsequence from currentIndex till the end of the array
  int findLDSLength(const vector<int> &nums, int currentIndex, int previousIndex) {
    if (currentIndex == nums.size()) {
      return 0;
    }

    // include nums[currentIndex] if it is smaller than the previous number
    int c1 = 0;
    if (previousIndex == -1 || nums[currentIndex] < nums[previousIndex]) {
      c1 = 1 + findLDSLength(nums, currentIndex + 1, currentIndex);
    }

    // excluding the number at currentIndex
    int c2 = findLDSLength(nums, currentIndex + 1, previousIndex);

    return max(c1, c2);
  }

  // find the longest decreasing subsequence from currentIndex till the beginning of the array
  int findLDSLengthRev(const vector<int> &nums, int currentIndex, int previousIndex) {
    if (currentIndex < 0) {
      return 0;
    }

    // include nums[currentIndex] if it is smaller than the previous number
    int c1 = 0;
    if (previousIndex == -1 || nums[currentIndex] < nums[previousIndex]) {
      c1 = 1 + findLDSLengthRev(nums, currentIndex - 1, currentIndex);
    }

    // excluding the number at currentIndex
    int c2 = findLDSLengthRev(nums, currentIndex - 1, previousIndex);

    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LBS *lbs = new LBS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lbs->findLBSLength(nums) << endl;
  nums = vector<int>{4, 2, 5, 9, 7, 6, 10, 3, 1};
  cout << lbs->findLBSLength(nums) << endl;

  delete lbs;
}
