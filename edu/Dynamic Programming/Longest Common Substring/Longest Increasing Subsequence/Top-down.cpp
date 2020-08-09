/*
Since our memoization array dp[nums.length()][nums.length()] stores the results
for all the subproblems, we can conclude that we will not have more than N*N
subproblems (where ‘N’ is the length of the input sequence). This means that
our time complexity will be O(N^2)

The above algorithm will be using O(N^2) space for the memoization array. Other
than that we will use O(N) space for the recursion call-stack. So the total
space complexity will be O(N^2 + N), which is asymptotically equivalent to O(N^2)
*/

using namespace std;

#include <iostream>
#include <vector>

class LIS {

public:
  int findLISLength(const vector<int> &nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    return findLISLengthRecursive(dp, nums, 0, -1);
  }

private:
  int findLISLengthRecursive(vector<vector<int>> &dp, const vector<int> &nums, int currentIndex,
                             int previousIndex) {
    if (currentIndex == nums.size()) {
      return 0;
    }

    if (dp[currentIndex][previousIndex + 1] == -1) {
      // include nums[currentIndex] if it is larger than the last included number
      int c1 = 0;
      if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
        c1 = 1 + findLISLengthRecursive(dp, nums, currentIndex + 1, currentIndex);
      }

      int c2 = findLISLengthRecursive(dp, nums, currentIndex + 1, previousIndex);
      dp[currentIndex][previousIndex + 1] = max(c1, c2);
    }

    return dp[currentIndex][previousIndex + 1];
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
