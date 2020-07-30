/*
Problem Statement #
Given two integer arrays to represent weights and profits of ‘N’ items, we need
to find a subset of these items which will give us maximum profit such that
their cumulative weight is not more than a given number ‘C’. Each item can only
be selected once, which means either we put an item in the knapsack or we skip
it.


Time and Space complexity #
The time complexity of the above algorithm is exponential O(2^n), where ‘n’
represents the total number of items. As we can see, we will have a total of
‘31’ recursive calls – calculated through (2^n) + (2^n) - 1, which is
asymptotically equivalent to O(2^n)

The space complexity is O(n). This space will be used to store the recursion
stack. Since the recursive algorithm works in a depth-first fashion, which means
that we can’t have more than ‘n’ recursive calls on the call stack at any time.
*/

using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
 public:
  int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity) {
    return this->knapsackRecursive(profits, weights, capacity, 0);
  }

 private:
  int knapsackRecursive(const vector<int> &profits, vector<int> &weights, int capacity,
                        int currentIndex) {
    // base checks
    if (capacity <= 0 || currentIndex >= profits.size()) {
      return 0;
    }

    // recursive call after choosing the element at the currentIndex
    // if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
      profit1 =
          profits[currentIndex] +
          knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);
    }

    // recursive call after excluding the element at the currentIndex
    int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

    return max(profit1, profit2);
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
