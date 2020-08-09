/*
The time complexity of the above algorithm is O(n^2) and the space complexity is O(n)
*/

using namespace std;

#include <iostream>
#include <vector>

class LIS {

public:
  int findLISLength(const vector<int> &nums) {
    vector<int> dp(nums.size());
    dp[0] = 1;

    int maxLength = 1;
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j] && dp[i] <= dp[j]) {
          dp[i] = dp[j] + 1;
          maxLength = max(maxLength, dp[i]);
        }
      }
    }
    return maxLength;
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
