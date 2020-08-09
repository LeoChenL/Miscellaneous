/*
Time and space complexity of O(N*C), where ‘N’ represents total items and ‘C’ is 
the maximum capacity.
*/


using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    // base checks
    if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
      return 0;
    }

    int n = profits.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1));

    // populate the capacity=0 columns
    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }

    // process all sub-arrays for all capacities
    for (int i = 0; i < n; i++) {
      for (int c = 1; c <= capacity; c++) {
        int profit1 = 0, profit2 = 0;
        if (weights[i] <= c) {
          profit1 = profits[i] + dp[i][c - weights[i]];
        }
        if (i > 0) {
          profit2 = dp[i - 1][c];
        }
        dp[i][c] = profit1 > profit2 ? profit1 : profit2;
      }
    }

    // maximum profit will be in the bottom-right corner.
    return dp[n - 1][capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack *ks = new Knapsack();
  vector<int> profits = {15, 50, 60, 90};
  vector<int> weights = {1, 3, 4, 5};
  cout << ks->solveKnapsack(profits, weights, 8) << endl;
  cout << ks->solveKnapsack(profits, weights, 6) << endl;

  delete ks;
}
