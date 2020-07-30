using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {
    int n = num.size();
    vector<bool> dp(sum + 1);

    // handle sum=0, as we can always have '0' sum with an empty set
    dp[0] = true;

    // with only one number, we can have a subset only when the required sum is equal to its value
    for (int s = 1; s <= sum; s++) {
      dp[s] = (num[0] == s ? true : false);
    }

    // process all subsets for all sums
    for (int i = 1; i < n; i++) {
      for (int s = sum; s >= 0; s--) {
        // if dp[s]==true, this means we can get the sum 's' without num[i], hence we can move on to
        // the next number else we can include num[i] and see if we can find a subset to get the
        // remaining sum
        if (!dp[s] && s >= num[i]) {
          dp[s] = dp[s - num[i]];
        }
      }
    }

    return dp[sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}
