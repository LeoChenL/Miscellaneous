/*
The above solution has time and space complexity of O(C*T), where ‘C’
represents total coin denominations and ‘T’ is the total amount that we want to
make change.
*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CoinChange {

public:
  int countChange(const vector<int> &denominations, int total) {
    int n = denominations.size();
    vector<vector<int>> dp(n, vector<int>(total + 1));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= total; j++) {
        dp[i][j] = numeric_limits<int>::max();
      }
    }

    // populate the total=0 columns, as we don't need any coin to make zero total
    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }

    for (int i = 0; i < n; i++) {
      for (int t = 1; t <= total; t++) {
        if (i > 0) {
          dp[i][t] = dp[i - 1][t]; // exclude the coin
        }
        if (t >= denominations[i]) {
          if (dp[i][t - denominations[i]] != numeric_limits<int>::max()) {
            dp[i][t] = min(dp[i][t], dp[i][t - denominations[i]] + 1); // include the coin
          }
        }
      }
    }

    // total combinations will be at the bottom-right corner.
    return (dp[n - 1][total] == numeric_limits<int>::max() ? -1 : dp[n - 1][total]);
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;
  cout << cc->countChange(denominations, 11) << endl;
  cout << cc->countChange(denominations, 7) << endl;
  denominations = vector<int>{3, 5};
  cout << cc->countChange(denominations, 7) << endl;

  delete cc;
}
