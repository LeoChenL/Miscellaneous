/*
Problem Statement #
Given strings s1 and s2, we need to transform s1 into s2 by deleting and
inserting characters. Write a function to calculate the count of the minimum
number of deletion and insertion operations.

Example 1:

Input: s1 = "abc"
       s2 = "fbc"
Output: 1 deletion and 1 insertion.
Explanation: We need to delete {'a'} and insert {'f'} to s1 to transform it
into s2.
Example 2:

Input: s1 = "abdca"
       s2 = "cbda"
Output: 2 deletions and 1 insertion.
Explanation: We need to delete {'a', 'c'} and insert {'c'} to s1 to transform
it into s2.
Example 3:

Input: s1 = "passport"
       s2 = "ppsspt"
Output: 3 deletions and 1 insertion
Explanation: We need to delete {'a', 'o', 'r'} and insert {'p'} to s1 to
transform it into s2.


The time and space complexity of the above algorithm is O(m*n), where ‘m’ and
‘n’ are the lengths of the two input strings.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class MDI {

public:
  void findMDI(const string &s1, const string &s2) {
    int c1 = findLCSLength(s1, s2);
    cout << "Minimum deletions needed: " << (s1.length() - c1) << endl;
    cout << "Minimum insertions needed: " << (s2.length() - c1) << endl;
  }

private:
  int findLCSLength(const string &s1, const string &s2) {
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
    int maxLength = 0;
    for (int i = 1; i <= s1.length(); i++) {
      for (int j = 1; j <= s2.length(); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

        maxLength = max(maxLength, dp[i][j]);
      }
    }
    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  MDI *mdi = new MDI();
  mdi->findMDI("abc", "fbc");
  mdi->findMDI("abdca", "cbda");
  mdi->findMDI("passport", "ppsspt");

  delete mdi;
}
