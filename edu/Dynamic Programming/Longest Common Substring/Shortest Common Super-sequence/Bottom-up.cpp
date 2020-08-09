/*
The time and space complexity of the above algorithm is O(n*m)
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class SCS {

public:
  int findSCSLength(const string &s1, const string &s2) {
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

    // if one of the strings is of zero length, SCS would be equal to the length of the other string
    for (int i = 0; i <= s1.length(); i++) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= s2.length(); j++) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= s1.length(); i++) {
      for (int j = 1; j <= s2.length(); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[s1.length()][s2.length()];
  }
};

int main(int argc, char *argv[]) {
  SCS *scs = new SCS();
  cout << scs->findSCSLength("abcf", "bdcf") << endl;
  cout << scs->findSCSLength("dynamic", "programming") << endl;

  delete scs;
}
