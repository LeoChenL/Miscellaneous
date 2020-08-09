using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayJump {

public:
  int countMinJumps(const vector<int> &jumps) {
    vector<int> dp(jumps.size(), 0);
    return this->countMinJumpsRecursive(dp, jumps, 0);
  }

private:
  int countMinJumpsRecursive(vector<int> &dp, const vector<int> &jumps, int currentIndex) {
    // if we have reached the last index, we don't need any more jumps
    if (currentIndex == jumps.size() - 1) {
      return 0;
    }

    // If an element is 0, then we cannot move through that element
    if (jumps[currentIndex] == 0) {
      return numeric_limits<int>::max();
    }

    // if we have already solved this problem, return the result
    if (dp[currentIndex] != 0) {
      return dp[currentIndex];
    }

    int totalJumps = numeric_limits<int>::max();
    int start = currentIndex + 1;
    int end = currentIndex + jumps[currentIndex];
    while (start < jumps.size() && start <= end) {
      // jump one step and recurse for the remaining array
      int minJumps = countMinJumpsRecursive(dp, jumps, start++);
      if (minJumps != numeric_limits<int>::max()) {
        totalJumps = min(totalJumps, minJumps + 1);
      }
    }
    dp[currentIndex] = totalJumps;
    return dp[currentIndex];
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