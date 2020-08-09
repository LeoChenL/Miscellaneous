/*
The above algorithm has a time and space complexity of O(n^2) because we will
not have more than n*nn∗n subproblems.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LPS {

public:
  int findLPSLength(const string &st) {
    vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
    return findLPSLengthRecursive(dp, st, 0, st.length() - 1);
  }

private:
  int findLPSLengthRecursive(vector<vector<int>> &dp, const string &st, int startIndex,
                             int endIndex) {
    if (startIndex > endIndex) {
      return 0;
    }

    // every string with one character is a palindrome
    if (startIndex == endIndex) {
      return 1;
    }

    if (dp[startIndex][endIndex] == -1) {
      int c1 = 0;
      // case 1: elements at the beginning and the end are the same
      if (st[startIndex] == st[endIndex]) {
        int remainingLength = endIndex - startIndex - 1;
        // if the remaining string is a palindrome too
        if (remainingLength == findLPSLengthRecursive(dp, st, startIndex + 1, endIndex - 1)) {
          c1 = remainingLength + 2;
        }
      }

      // case 2: skip one character either from the beginning or the end
      int c2 = findLPSLengthRecursive(dp, st, startIndex + 1, endIndex);
      int c3 = findLPSLengthRecursive(dp, st, startIndex, endIndex - 1);
      dp[startIndex][endIndex] = max(c1, max(c2, c3));
    }

    return dp[startIndex][endIndex];
  }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}
