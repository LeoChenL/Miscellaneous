/*
a time complexity of O(n^2) (because of the two for loops) and space complexity
of O(n) to store dp[].
*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayJump {

public:
  int countMinJumps(const vector<int> &jumps) {
    vector<int> dp(jumps.size());

    // initialize with infinity, except the first index which should be zero as we start from there
    for (int i = 1; i < jumps.size(); i++) {
      dp[i] = numeric_limits<int>::max();
    }

    for (int start = 0; start < jumps.size() - 1; start++) {
      for (int end = start + 1; end <= start + jumps[start] && end < jumps.size(); end++) {
        dp[end] = min(dp[end], dp[start] + 1);
      }
    }

    return dp[jumps.size() - 1];
  }
};

int main(int argc, char *argv[]) {
  ArrayJump *aj = new ArrayJump();
  vector<int> jumps = {2, 1, 1, 1, 4};
  cout << aj->countMinJumps(jumps) << endl;
  jumps = vector<int>{1, 1, 3, 6, 9, 3, 0, 1, 3};
  cout << aj->countMinJumps(jumps) << endl;

  delete aj;
}
