/*
Since our memoization array dp[s1.length()][s2.length()] stores the results for
all the subproblems, we can conclude that we will not have more than m*n
subproblems (where ‘m’ and ‘n’ are the lengths of the two input strings.). This
means that our time complexity will be O(m*n).

The above algorithm will be using O(m*n) space for the memoization array.
Other than that we will use O(m+n) space for the recursion call-stack. So the
total space complexity will be O(m*n + (m+n)), which is asymptotically
equivalent to O(m∗n).
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class EditDistance {

public:
  int findMinOperations(const string &s1, const string &s2) {
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return findMinOperationsRecursive(dp, s1, s2, 0, 0);
  }

private:
  int findMinOperationsRecursive(vector<vector<int>> &dp, const string &s1, const string &s2,
                                 int i1, int i2) {

    if (dp[i1][i2] == -1) {
      // if we have reached the end of s1, then we have to insert all the remaining
      // characters of s2
      if (i1 == s1.length()) {
        dp[i1][i2] = s2.length() - i2;
      }

      // if we have reached the end of s2, then we have to delete all the remaining
      // characters of s1
      else if (i2 == s2.length()) {
        dp[i1][i2] = s1.length() - i1;
      }

      // If the strings have a matching character, we can recursively match for the
      // remaining lengths
      else if (s1[i1] == s2[i2]) {
        dp[i1][i2] = findMinOperationsRecursive(dp, s1, s2, i1 + 1, i2 + 1);
      } else {
        int c1 = findMinOperationsRecursive(dp, s1, s2, i1 + 1, i2);     // delete
        int c2 = findMinOperationsRecursive(dp, s1, s2, i1, i2 + 1);     // insert
        int c3 = findMinOperationsRecursive(dp, s1, s2, i1 + 1, i2 + 1); // replace
        dp[i1][i2] = 1 + min(c1, min(c2, c3));
      }
    }

    return dp[i1][i2];
  }
};

int main(int argc, char *argv[]) {
  EditDistance *editDisatnce = new EditDistance();
  cout << editDisatnce->findMinOperations("bat", "but") << endl;
  cout << editDisatnce->findMinOperations("abdca", "cbda") << endl;
  cout << editDisatnce->findMinOperations("passpot", "ppsspqrt") << endl;

  delete editDisatnce;
}
