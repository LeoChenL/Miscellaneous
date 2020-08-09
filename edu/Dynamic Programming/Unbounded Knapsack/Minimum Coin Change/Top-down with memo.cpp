using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CoinChange {

public:
  int countChange(const vector<int> &denominations, int total) {
    vector<vector<int>> dp(denominations.size(), vector<int>(total + 1));
    int result = this->countChangeRecursive(dp, denominations, total, 0);
    return (result == numeric_limits<int>::max() ? -1 : result);
  }

private:
  int countChangeRecursive(vector<vector<int>> &dp, const vector<int> &denominations, int total,
                           int currentIndex) {
    // base check
    if (total == 0) {
      return 0;
    }

    if (denominations.empty() || currentIndex >= denominations.size()) {
      return numeric_limits<int>::max();
    }

    // check if we have not already processed a similar sub-problem
    if (!dp[currentIndex][total]) {
      // recursive call after selecting the coin at the currentIndex
      // if the coin at currentIndex exceeds the total, we shouldn't process this
      int count1 = numeric_limits<int>::max();
      if (denominations[currentIndex] <= total) {
        int res = countChangeRecursive(dp, denominations, total - denominations[currentIndex],
                                       currentIndex);
        if (res != numeric_limits<int>::max()) {
          count1 = res + 1;
        }
      }

      // recursive call after excluding the coin at the currentIndex
      int count2 = countChangeRecursive(dp, denominations, total, currentIndex + 1);
      dp[currentIndex][total] = min(count1, count2);
    }
    return dp[currentIndex][total];
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
