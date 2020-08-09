using namespace std;

#include <iostream>
#include <string>
#include <vector>

class MPP {

public:
  int findMPPCuts(const string &st) {
    vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
    vector<vector<int>> dpIsPalindrome(st.length(), vector<int>(st.length(), -1));
    return this->findMPPCutsRecursive(dp, dpIsPalindrome, st, 0, st.length() - 1);
  }

private:
  int findMPPCutsRecursive(vector<vector<int>> &dp, vector<vector<int>> &dpIsPalindrome,
                           const string &st, int startIndex, int endIndex) {

    if (startIndex >= endIndex || isPalindrome(dpIsPalindrome, st, startIndex, endIndex)) {
      return 0;
    }

    if (dp[startIndex][endIndex] == -1) {
      // at max, we need to cut the string into its 'length-1' pieces
      int minimumCuts = endIndex - startIndex;
      for (int i = startIndex; i <= endIndex; i++) {
        if (isPalindrome(dpIsPalindrome, st, startIndex, i)) {
          // we can cut here as we have a palindrome from 'startIndex' to 'i'
          minimumCuts =
              min(minimumCuts, 1 + findMPPCutsRecursive(dp, dpIsPalindrome, st, i + 1, endIndex));
        }
      }
      dp[startIndex][endIndex] = minimumCuts;
    }
    return dp[startIndex][endIndex];
  }

  bool isPalindrome(vector<vector<int>> &dpIsPalindrome, const string &st, int x, int y) {
    if (dpIsPalindrome[x][y] == -1) {
      dpIsPalindrome[x][y] = 1;
      int i = x, j = y;
      while (i < j) {
        if (st[i++] != st[j--]) {
          dpIsPalindrome[x][y] = 0;
          break;
        }
        // use memoization to find if the remaining string is a palindrome
        if (i < j && dpIsPalindrome[i][j] == 1) {
          dpIsPalindrome[x][y] = dpIsPalindrome[i][j];
          break;
        }
      }
    }
    
    return dpIsPalindrome[x][y] == 1;
  }
};

int main(int argc, char *argv[]) {
  MPP *mpp = new MPP();
  cout << mpp->findMPPCuts("abdbca") << endl;
  cout << mpp->findMPPCuts("cdpdd") << endl;
  cout << mpp->findMPPCuts("pqr") << endl;
  cout << mpp->findMPPCuts("pp") << endl;

  delete mpp;
}
