/*
Problem Statement #
Given two integer arrays to represent weights and profits of ‘N’ items, we need
to find a subset of these items which will give us maximum profit such that
their cumulative weight is not more than a given number ‘C’. Each item can only
be selected once, which means either we put an item in the knapsack or we skip
it.


Time and Space complexity #
Since our memoization array dp[profits.length][capacity+1] stores the results
for all subproblems, we can conclude that we will not have more than N*C
subproblems (where ‘N’ is the number of items and ‘C’ is the knapsack capacity).
This means that our time complexity will be O(N*C).

The above algorithm will use O(N*C) space for the memoization array. Other than
that we will use O(N) space for the recursion call-stack. So the total space
complexity will be O(N*C + N), which is asymptotically equivalent to O(N∗C).
*/

using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
 public:
  virtual int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity) {
    vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, -1));
    return this->knapsackRecursive(dp, profits, weights, capacity, 0);
  }

 private:
  int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits, vector<int> &weights,
                        int capacity, int currentIndex) {
    // base checks
    if (capacity <= 0 || currentIndex >= profits.size()) {
      return 0;
    }

    // if we have already solved a similar problem, return the result from memory
    if (dp[currentIndex][capacity] != -1) {
      return dp[currentIndex][capacity];
    }

    // recursive call after choosing the element at the currentIndex
    // if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
      profit1 = profits[currentIndex] + knapsackRecursive(dp, profits, weights,
                                                          capacity - weights[currentIndex],
                                                          currentIndex + 1);
    }

    // recursive call after excluding the element at the currentIndex
    int profit2 = knapsackRecursive(dp, profits, weights, capacity, currentIndex + 1);

    dp[currentIndex][capacity] = max(profit1, profit2);
    return dp[currentIndex][capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}
