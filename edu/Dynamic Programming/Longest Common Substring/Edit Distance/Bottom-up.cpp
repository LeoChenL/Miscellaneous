/*
The time and space complexity of the above algorithm is O(n*m), where ‘m’ and
‘n’ are the lengths of the two input strings.
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class EditDistance {

public:
  int findMinOperations(const string &s1, const string &s2) {
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

    // if s2 is empty, we can remove all the characters of s1 to make it empty too
    for (int i1 = 0; i1 <= s1.length(); i1++) {
      dp[i1][0] = i1;
    }

    // if s1 is empty, we have to insert all the characters of s2
    for (int i2 = 0; i2 <= s2.length(); i2++) {
      dp[0][i2] = i2;
    }

    for (int i1 = 1; i1 <= s1.length(); i1++) {
      for (int i2 = 1; i2 <= s2.length(); i2++) {
        // If the strings have a matching character, we can recursively match for the
        // remaining lengths
        if (s1[i1 - 1] == s2[i2 - 1]) {
          dp[i1][i2] = dp[i1 - 1][i2 - 1];
        } else {
          dp[i1][i2] = 1 + min(dp[i1 - 1][i2], min(dp[i1][i2 - 1], dp[i1 - 1][i2 - 1])); // replace
        }
      }
    }

    return dp[s1.length()][s2.length()];
  }
};

int main(int argc, char *argv[]) {
  EditDistance *editDisatnce = new EditDistance();
  cout << editDisatnce->findMinOperations("bat", "but") << endl;
  cout << editDisatnce->findMinOperations("abdca", "cbda") << endl;
  cout << editDisatnce->findMinOperations("passpot", "ppsspqrt") << endl;

  delete editDisatnce;
}