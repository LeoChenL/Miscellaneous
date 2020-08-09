/*
Problem Statement #
Given a string, find the minimum number of characters that we can remove to
make it a palindrome.

Example 1:

Input: "abdbca"
Output: 1
Explanation: By removing "c", we get a palindrome "abdba".
Example 2:

Input: = "cddpd"
Output: 2
Explanation: Deleting "cp", we get a palindrome "ddd".
Example 3:

Input: = "pqr"
Output: 2
Explanation: We have to remove any two characters to get a palindrome, e.g.
if we remove "pq", we get palindrome "r".


The time and space complexity of the above algorithm is O(n^2), where ‘n’ is
the length of the input string.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class MDSP {

public:
  int findMinimumDeletions(const string &st) {
    // subtracting the length of Longest Palindromic Subsequence from the length of
    // the input string to get minimum number of deletions
    return st.length() - findLPSLength(st);
  }

  int findLPSLength(const string &st) {
    // dp[i][j] stores the length of LPS from index 'i' to index 'j'
    vector<vector<int>> dp(st.length(), vector<int>(st.length()));

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
  MDSP *mdsp = new MDSP();
  cout << mdsp->findMinimumDeletions("abdbca") << endl;
  cout << mdsp->findMinimumDeletions("cddpd") << endl;
  cout << mdsp->findMinimumDeletions("pqr") << endl;

  delete mdsp;
}
