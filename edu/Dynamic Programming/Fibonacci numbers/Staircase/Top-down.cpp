/*
Since our memoization array dp[n+1] stores the results for all the subproblems,
we can conclude that we will not have more than n+1 subproblems (where ‘n’
represents the total number of steps). This means that our time complexity will
be O(N). The space complexity will also be O(n); this space will be used to 
store the recursion-stack.
*/


using namespace std;

#include <iostream>
#include <vector>

class Staircase {

public:
  int CountWays(int n) {
    vector<int> dp(n + 1, 0);
    return CountWaysRecursive(dp, n);
  }

  int CountWaysRecursive(vector<int> &dp, int n) {
    if (n == 0) {
      return 1; // base case, we don't need to take any step, so there is only one way
    }

    if (n == 1) {
      return 1; // we can take one step to reach the end, and that is the only way
    }

    if (n == 2) {
      return 2; // we can take one step twice or jump two steps to reach at the top
    }

    if (dp[n] == 0) {
      // if we take 1 step, we are left with 'n-1' steps;
      int take1Step = CountWaysRecursive(dp, n - 1);
      // similarly, if we took 2 steps, we are left with 'n-2' steps;
      int take2Step = CountWaysRecursive(dp, n - 2);
      // if we took 3 steps, we are left with 'n-3' steps;
      int take3Step = CountWaysRecursive(dp, n - 3);
      dp[n] = take1Step + take2Step + take3Step;
    }

    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  cout << sc->CountWays(3) << endl;
  cout << sc->CountWays(4) << endl;
  cout << sc->CountWays(5) << endl;

  delete sc;
}
