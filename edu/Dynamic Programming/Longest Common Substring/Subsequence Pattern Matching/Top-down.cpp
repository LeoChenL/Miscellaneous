using namespace std;

#include <iostream>
#include <string>
#include <vector>

class SPM {

public:
  int findSPMCount(const string &str, const string &pat) {
    vector<vector<int>> dp(str.length(), vector<int>(pat.length(), -1));
    return findSPMCountRecursive(dp, str, pat, 0, 0);
  }

private:
  int findSPMCountRecursive(vector<vector<int>> &dp, const string &str, const string &pat,
                            int strIndex, int patIndex) {

    // if we have reached the end of the pattern
    if (patIndex == pat.length()) {
      return 1;
    }

    // if we have reached the end of the string but pattern has still some characters left
    if (strIndex == str.length()) {
      return 0;
    }

    if (dp[strIndex][patIndex] == -1) {
      int c1 = 0;
      if (str[strIndex] == pat[patIndex]) {
        c1 = findSPMCountRecursive(dp, str, pat, strIndex + 1, patIndex + 1);
      }
      int c2 = findSPMCountRecursive(dp, str, pat, strIndex + 1, patIndex);
      dp[strIndex][patIndex] = c1 + c2;
    }

    return dp[strIndex][patIndex];
  }
};

int main(int argc, char *argv[]) {
  SPM *spm = new SPM();
  cout << spm->findSPMCount("baxmx", "ax") << endl;
  cout << spm->findSPMCount("tomorrow", "tor") << endl;

  delete spm;
}