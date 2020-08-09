/*
Problem Statement #
Given two integer arrays to represent weights and profits of ‘N’ items, we need
to find a subset of these items which will give us maximum profit such that
their cumulative weight is not more than a given number ‘C’. We can assume an
infinite supply of item quantities; therefore, each item can be selected
multiple times.

basic brute-force solution
for each item 'i'
  create a new set which includes one quantity of item 'i' if it does not exceed
   the capacity, and 
     recursively call to process all items
  create a new set without item 'i', and recursively process the remaining items
return the set from the above two sets with higher profit


The time complexity of the above algorithm is exponential O(2^{N+C}), where ‘N’
represents the total number of items. The space complexity will be O(N+C) to
store the recursion stack.
*/


using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    return this->knapsackRecursive(profits, weights, capacity, 0);
  }

private:
  int knapsackRecursive(const vector<int> &profits, const vector<int> &weights, int capacity,
                        int currentIndex) {
    // base checks
    if (capacity <= 0 || profits.empty() || weights.size() != profits.size() ||
        currentIndex >= profits.size()) {
      return 0;
    }

    // recursive call after choosing the items at the currentIndex, note that we recursive call on
    // all items as we did not increment currentIndex
    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
      profit1 = profits[currentIndex] +
                knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex);
    }

    // recursive call after excluding the element at the currentIndex
    int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

    return max(profit1, profit2);
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
