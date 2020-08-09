using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LCS {
public:
  int findLCSLength(const string &s1, const string &s2) {
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    return findLCSLengthRecursive(dp, s1, s2, 0, 0);
  }

private:
  int findLCSLengthRecursive(vector<vector<int>> &dp, const string &s1, const string &s2, int i1,
                             int i2) {
    if (i1 == s1.length() || i2 == s2.length()) {
      return 0;
    }

    if (dp[i1][i2] == -1) {
      if (s1[i1] == s2[i2]) {
        dp[i1][i2] = 1 + findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2 + 1);
      } else {
        int c1 = findLCSLengthRecursive(dp, s1, s2, i1, i2 + 1);
        int c2 = findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2);
        dp[i1][i2] = max(c1, c2);
      }
    }

    return dp[i1][i2];
  }
};

int main(int argc, char *argv[]) {
  LCS *lcs = new LCS();
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;

  delete lcs;
}