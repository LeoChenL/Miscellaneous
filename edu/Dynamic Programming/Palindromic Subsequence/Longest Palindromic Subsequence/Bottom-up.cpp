/*
The time and space complexity of the above algorithm is O(n^2), where ‘n’ is
the length of the input sequence
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LPS {

public:
  int findLPSLength(const string &st) {
    vector<vector<int>> dp(st.length(), vector<int>(st.length(), 0));
    // every sequence with one element is a palindrome of length 1
    for (int i = 0; i < st.length(); i++) {
      dp[i][i] = 1;
    }

    for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
      for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
        // case 1: elements at the beginning and the end are the same
        if (st[startIndex] == st[endIndex]) {
          dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1];
        } else { // case 2: skip one element either from the beginning or the end
          dp[startIndex][endIndex] =
              max(dp[startIndex + 1][endIndex], dp[startIndex][endIndex - 1]);
        }
      }
    }
    return dp[0][st.length() - 1];
  }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}
