/*
The time complexity of the above algorithm is O(n^2) and the space complexity
is O(n).
*/

using namespace std;

#include <iostream>
#include <vector>

class MSIS {

public:
  int findMSIS(const vector<int> &nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];

    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = nums[i];
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j] && dp[i] < dp[j] + nums[i]) {
          dp[i] = dp[j] + nums[i];
        }
      }
      maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
  }
};

int main(int argc, char *argv[]) {
  MSIS *msis = new MSIS();
  vector<int> nums = {4, 1, 2, 6, 10, 1, 12};
  cout << msis->findMSIS(nums) << endl;
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << msis->findMSIS(nums) << endl;
  nums = vector<int>{1, 3, 8, 4, 14, 6, 14, 1, 9, 4, 13, 3, 11, 17, 29};
  cout << msis->findMSIS(nums) << endl;

  delete msis;
}
