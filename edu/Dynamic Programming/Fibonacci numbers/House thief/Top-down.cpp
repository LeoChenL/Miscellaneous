using namespace std;

#include <iostream>
#include <vector>

class HouseThief {
public:
  int findMaxSteal(const vector<int> &wealth) {
    vector<int> dp(wealth.size(), 0);
    return findMaxStealRecursive(dp, wealth, 0);
  }

private:
  int findMaxStealRecursive(vector<int> &dp, const vector<int> &wealth, int currentIndex) {
    if (currentIndex >= wealth.size()) {
      return 0;
    }
    if (dp[currentIndex] == 0) {
      // steal from current house and skip one to steal next
      int stealCurrent = wealth[currentIndex] + findMaxStealRecursive(dp, wealth, currentIndex + 2);
      // skip current house to steel from the adjacent house
      int skipCurrent = findMaxStealRecursive(dp, wealth, currentIndex + 1);

      dp[currentIndex] = max(stealCurrent, skipCurrent);
    }
    return dp[currentIndex];
  }
};

int main(int argc, char *argv[]) {
  HouseThief *ht = new HouseThief();
  vector<int> wealth = {2, 5, 1, 3, 6, 2, 4};
  cout << ht->findMaxSteal(wealth) << endl;
  wealth = vector<int>{2, 10, 14, 8, 1};
  cout << ht->findMaxSteal(wealth) << endl;

  delete ht;
}
