using namespace std;

#include <iostream>
#include <vector>

class TargetSum {
 public:
  int findTargetSubsets(const vector<int> &num, int s) {
    int totalSum = 0;
    for (auto n : num) {
      totalSum += n;
    }

    // if 's + totalSum' is odd, we can't find a subset with sum equal to '(s + totalSum) / 2'
    if (totalSum < s || (s + totalSum) % 2 == 1) {
      return 0;
    }

    return countSubsets(num, (s + totalSum) / 2);
  }

  // this function is exactly similar to what we have in 'Count of Subset Sum' problem.
 private:
  int countSubsets(const vector<int> &num, int sum) {
    int n = num.size();
    vector<int> dp(sum + 1);
    dp[0] = 1;

    // with only one number, we can form a subset only when the required sum is
    // equal to the number
    for (int s = 1; s <= sum; s++) {
      dp[s] = (num[0] == s ? 1 : 0);
    }

    // process all subsets for all sums
    for (int i = 1; i < num.size(); i++) {
      for (int s = sum; s >= 0; s--) {
        if (s >= num[i]) {
          dp[s] += dp[s - num[i]];
        }
      }
    }

    return dp[sum];
  }
};

int main(int argc, char *argv[]) {
  TargetSum ts;
  vector<int> num = {1, 1, 2, 3};
  cout << ts.findTargetSubsets(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << ts.findTargetSubsets(num, 9) << endl;
}
