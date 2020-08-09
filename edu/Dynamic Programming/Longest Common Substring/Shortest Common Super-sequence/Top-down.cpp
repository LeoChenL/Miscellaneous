using namespace std;

#include <iostream>
#include <string>
#include <vector>

class SCS {

public:
  int findSCSLength(const string &s1, const string &s2) {
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    return findSCSLengthRecursive(dp, s1, s2, 0, 0);
  }

private:
  int findSCSLengthRecursive(vector<vector<int>> &dp, const string &s1, const string &s2, int i1,
                             int i2) {
    // if we have reached the end of a string, return the remaining length of the other string,
    // as in this case we have to take all of the remaining other string
    if (i1 == s1.length()) {
      return s2.length() - i2;
    }
    if (i2 == s2.length()) {
      return s1.length() - i1;
    }

    if (dp[i1][i2] == -1) {
      if (s1[i1] == s2[i2]) {
        dp[i1][i2] = 1 + findSCSLengthRecursive(dp, s1, s2, i1 + 1, i2 + 1);
      } else {
        int length1 = 1 + findSCSLengthRecursive(dp, s1, s2, i1, i2 + 1);
        int length2 = 1 + findSCSLengthRecursive(dp, s1, s2, i1 + 1, i2);
        dp[i1][i2] = min(length1, length2);
      }
    }

    return dp[i1][i2];
  }
};

int main(int argc, char *argv[]) {
  SCS *scs = new SCS();
  cout << scs->findSCSLength("abcf", "bdcf") << endl;
  cout << scs->findSCSLength("dynamic", "programming") << endl;

  delete scs;
}
