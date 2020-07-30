using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
 public:
  static int countSubsets(const vector<int> &num, int sum) {
    int n = num.size();
    vector<int> dp(sum + 1);
    dp[0] = 1;

    // with only one number, we can form a subset only when the required sum is
    // equal to its value
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
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 3};
  cout << ss.countSubsets(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.countSubsets(num, 9) << endl;
}
