using namespace std;

#include <iostream>
#include <vector>

class LAS {

public:
  int findLASLength(const vector<int> &nums) {
    vector<vector<vector<int>>> dp(nums.size(),
                                   vector<vector<int>>(nums.size(), vector<int>(2, -1)));
    return max(findLASLengthRecursive(dp, nums, -1, 0, true),
               findLASLengthRecursive(dp, nums, -1, 0, false));
  }

private:
  int findLASLengthRecursive(vector<vector<vector<int>>> &dp, const vector<int> &nums,
                             int previousIndex, int currentIndex, bool isAsc) {

    if (currentIndex == nums.size()) {
      return 0;
    }

    if (dp[previousIndex + 1][currentIndex][isAsc ? 1 : 0] == -1) {
      int c1 = 0;
      // if ascending, the next element should be bigger
      if (isAsc) {
        if (previousIndex == -1 || nums[previousIndex] < nums[currentIndex]) {
          c1 = 1 + this->findLASLengthRecursive(dp, nums, currentIndex, currentIndex + 1, !isAsc);
        }
      } else { // if descending, the next element should be smaller
        if (previousIndex == -1 || nums[previousIndex] > nums[currentIndex]) {
          c1 = 1 + this->findLASLengthRecursive(dp, nums, currentIndex, currentIndex + 1, !isAsc);
        }
      }
      // skip the current element
      int c2 = this->findLASLengthRecursive(dp, nums, previousIndex, currentIndex + 1, isAsc);
      dp[previousIndex + 1][currentIndex][isAsc ? 1 : 0] = max(c1, c2);
    }

    return dp[previousIndex + 1][currentIndex][isAsc ? 1 : 0];
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
