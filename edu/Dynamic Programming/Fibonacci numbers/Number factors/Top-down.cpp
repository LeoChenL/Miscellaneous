using namespace std;

#include <iostream>
#include <vector>

class ExpressNumber {

public:
  int CountWays(int n) {
    vector<int> dp(n + 1, 0);
    return CountWaysRecursive(dp, n);
  }

  int CountWaysRecursive(vector<int> &dp, int n) {
    if (n == 0) {
      return 1; // base case, we don't need to subtract any thing, so there is only one way
    }

    if (n == 1) {
      return 1; // we can take subtract 1 to be left with zero, and that is the only way
    }

    if (n == 2) {
      return 1; // we can subtract 1 twice to get zero and that is the only way
    }

    if (n == 3) {
      return 2; // '3' can be expressed as {1,1,1}, {3}
    }

    if (dp[n] == 0) {
      // if we subtract 1, we are left with 'n-1'
      int subtract1 = CountWaysRecursive(dp, n - 1);
      // if we subtract 3, we are left with 'n-3'
      int subtract3 = CountWaysRecursive(dp, n - 3);
      // if we subtract 4, we are left with 'n-4'
      int subtract4 = CountWaysRecursive(dp, n - 4);
      dp[n] = subtract1 + subtract3 + subtract4;
    }

    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  ExpressNumber *en = new ExpressNumber();
  cout << en->CountWays(4) << endl;
  cout << en->CountWays(5) << endl;
  cout << en->CountWays(6) << endl;

  delete en;
}
