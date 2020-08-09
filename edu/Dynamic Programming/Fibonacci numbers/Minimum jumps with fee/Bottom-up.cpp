/*
time and space complexity of O(n)
*/

using namespace std;

#include <iostream>
#include <vector>

class Staircase {

public:
  int findMinFee(const vector<int> &fee) {
    vector<int> dp(fee.size() + 1); // +1 to handle the 0th step
    dp[0] = 0;                      // if there are no steps, we dont have to pay any fee
    dp[1] = fee[0];                 // only one step, so we have to pay its fee
    // for 2 steps, since we start from the first step, so we have to pay its fee
    // and from the first step we can reach the top by taking two steps, so
    // we dont have to pay any other fee.
    dp[2] = fee[0];

    // please note that dp[] has one extra element to handle the 0th step
    for (int i = 2; i < fee.size(); i++) {
      dp[i + 1] = min(fee[i] + dp[i], min(fee[i - 1] + dp[i - 1], fee[i - 2] + dp[i - 2]));
    }

    return dp[fee.size()];
  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  vector<int> fee = {1, 2, 5, 2, 1, 2};
  cout << sc->findMinFee(fee) << endl;
  fee = vector<int>{2, 3, 4, 5};
  cout << sc->findMinFee(fee) << endl;

  delete sc;
}
