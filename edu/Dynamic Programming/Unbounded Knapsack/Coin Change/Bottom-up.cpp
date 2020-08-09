/*
The above solution has time and space complexity of O(C*T), where ‘C’
represents total coin denominations and ‘T’ is the total amount that we want to
make change.
*/

using namespace std;

#include <iostream>
#include <vector>

class CoinChange {

public:
  int countChange(const vector<int> &denominations, int total) {
    int n = denominations.size();
    vector<vector<int>> dp(n, vector<int>(total + 1));

    // populate the total=0 columns, as we will always have an empty set for zero total
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }
    // process all sub-arrays for all capacities

    for (int i = 0; i < n; i++) {
      for (int t = 1; t <= total; t++) {
        if (i > 0) {
          dp[i][t] = dp[i - 1][t];
        }
        if (t >= denominations[i]) {
          dp[i][t] += dp[i][t - denominations[i]];
        }
      }
    }

    // total combinations will be at the bottom-right corner.
    return dp[n - 1][total];
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;

  delete cc;
}
