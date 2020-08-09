/*
The time and space complexity of the above algorithm is O(m∗n), where ‘m’ and
‘n’ are the lengths of the string and the pattern respectively.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class SPM {

public:
  int findSPMCount(const string &str, const string &pat) {
    // every empty pattern has one match
    if (pat.length() == 0) {
      return 1;
    }

    if (str.length() == 0 || pat.length() > str.length()) {
      return 0;
    }

    // dp[strIndex][patIndex] will be storing the count of SPM up to
    // str[0..strIndex-1][0..patIndex-1]
    vector<vector<int>> dp(str.length() + 1, vector<int>(pat.length() + 1));

    // for the empty pattern, we have one matching
    for (int i = 0; i <= str.length(); i++) {
      dp[i][0] = 1;
    }

    for (int strIndex = 1; strIndex <= str.length(); strIndex++) {
      for (int patIndex = 1; patIndex <= pat.length(); patIndex++) {
        if (str[strIndex - 1] == pat[patIndex - 1]) {
          dp[strIndex][patIndex] = dp[strIndex - 1][patIndex - 1];
        }
        dp[strIndex][patIndex] += dp[strIndex - 1][patIndex];
      }
    }

    return dp[str.length()][pat.length()];
  }
};

int main(int argc, char *argv[]) {
  SPM *spm = new SPM();
  cout << spm->findSPMCount("baxmx", "ax") << endl;
  cout << spm->findSPMCount("tomorrow", "tor") << endl;

  delete spm;
}
