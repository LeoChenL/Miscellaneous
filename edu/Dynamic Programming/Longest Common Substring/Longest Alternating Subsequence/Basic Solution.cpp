/*
Problem Statement #
Given a number sequence, find the length of its Longest Alternating Subsequence
(LAS). A subsequence is considered alternating if its elements are in
alternating order.

A three element sequence (a1, a2, a3) will be an alternating sequence if its
elements hold one of the following conditions:

{a1 > a2 < a3 } or { a1 < a2 > a3}.
Example 1:

Input: {1,2,3,4}
Output: 2
Explanation: There are many LAS: {1,2}, {3,4}, {1,3}, {1,4}
Example 2:

Input: {3,2,1,4}
Output: 3
Explanation: The LAS are {3,2,4} and {2,1,4}.
Example 3:

Input: {1,3,2,4}
Output: 4
Explanation: The LAS is {1,3,2,4}.


The time complexity of the above algorithm is exponential O(2^n), where ‘n’ is
the lengths of the input array. The space complexity is O(n) which is used to
store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <vector>

class LAS {

public:
  int findLASLength(const vector<int> &nums) {
    // we have to start with two recursive calls, one where we will consider that the first element
    // is bigger than the second element and one where the first element is smaller than the second
    // element
    return max(findLASLengthRecursive(nums, -1, 0, true),
               findLASLengthRecursive(nums, -1, 0, false));
  }

private:
  int findLASLengthRecursive(const vector<int> &nums, int previousIndex, int currentIndex,
                             bool isAsc) {
    if (currentIndex == nums.size()) {
      return 0;
    }

    int c1 = 0;
    // if ascending, the next element should be bigger
    if (isAsc) {
      if (previousIndex == -1 || nums[previousIndex] < nums[currentIndex]) {
        c1 = 1 + this->findLASLengthRecursive(nums, currentIndex, currentIndex + 1, !isAsc);
      }
    } else { // if descending, the next element should be smaller
      if (previousIndex == -1 || nums[previousIndex] > nums[currentIndex]) {
        c1 = 1 + this->findLASLengthRecursive(nums, currentIndex, currentIndex + 1, !isAsc);
      }
    }
    // skip the current element
    int c2 = this->findLASLengthRecursive(nums, previousIndex, currentIndex + 1, isAsc);
    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LAS *las = new LAS();
  vector<int> nums = {1, 2, 3, 4};
  cout << las->findLASLength(nums) << endl;
  nums = vector<int>{3, 2, 1, 4};
  cout << las->findLASLength(nums) << endl;
  nums = vector<int>{1, 3, 2, 4};
  cout << las->findLASLength(nums) << endl;

  delete las;
}
