using namespace std;

#include <iostream>
#include <vector>

class Staircase {

public:
  int findMinFee(const vector<int> &fee) {
    vector<int> dp(fee.size(), 0);
    return findMinFeeRecursive(dp, fee, 0);
  }

private:
  int findMinFeeRecursive(vector<int> &dp, const vector<int> &fee, int currentIndex) {
    if (currentIndex > fee.size() - 1) {
      return 0;
    }

    if (dp[currentIndex] == 0) {
      // if we take 1 step, we are left with 'n-1' steps;
      int take1Step = findMinFeeRecursive(dp, fee, currentIndex + 1);
      // similarly, if we took 2 steps, we are left with 'n-2' steps;
      int take2Step = findMinFeeRecursive(dp, fee, currentIndex + 2);
      // if we took 3 steps, we are left with 'n-3' steps;
      int take3Step = findMinFeeRecursive(dp, fee, currentIndex + 3);

      dp[currentIndex] = fee[currentIndex] + min(min(take1Step, take2Step), take3Step);
    }

    return dp[currentIndex];
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