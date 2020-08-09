/*
The time and space complexity of the above algorithm is O(n^2), where ‘n’ is
the length of the input string.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LPS {

public:
  int findLPSLength(const string &st) {
    // dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
    vector<vector<bool>> dp(st.length(), vector<bool>(st.length()));

    // every string with one character is a palindrome
    for (int i = 0; i < st.length(); i++) {
      dp[i][i] = true;
    }

    int maxLength = 1;
    for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
      for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
        if (st[startIndex] == st[endIndex]) {
          // if it's a two character string or if the remaining string is a palindrome too
          if (endIndex - startIndex == 1 || dp[startIndex + 1][endIndex - 1]) {
            dp[startIndex][endIndex] = true;
            maxLength = max(maxLength, endIndex - startIndex + 1);
          }
        }
      }
    }

    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cdpdd") << endl;
  cout << lps->findLPSLength("pqr") << endl;
  cout << lps->findLPSLength("madam") << endl;

  delete lps;
}
