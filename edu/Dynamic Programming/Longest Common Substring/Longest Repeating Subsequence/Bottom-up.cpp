/*
The time and space complexity of the above algorithm is O(n^2), where ‘n’ is
the length of the input sequence.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LRS {

public:
  int findLRSLength(const string &str) {
    vector<vector<int>> dp(str.length() + 1, vector<int>(str.length() + 1));
    int maxLength = 0;
    // dp[i1][i2] will be storing the LRS up to str[0..i1-1][0..i2-1]
    // this also means that subsequences of length zero (first row and column of dp[][]), will
    // always have LRS of size zero.
    for (int i1 = 1; i1 <= str.length(); i1++) {
      for (int i2 = 1; i2 <= str.length(); i2++) {
        if (i1 != i2 && str[i1 - 1] == str[i2 - 1]) {
          dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
        } else {
          dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
        }

        maxLength = max(maxLength, dp[i1][i2]);
      }
    }
    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  LRS *lrs = new LRS();
  cout << lrs->findLRSLength("tomorrow") << endl;
  cout << lrs->findLRSLength("aabdbcec") << endl;
  cout << lrs->findLRSLength("fmff") << endl;

  delete lrs;
}
