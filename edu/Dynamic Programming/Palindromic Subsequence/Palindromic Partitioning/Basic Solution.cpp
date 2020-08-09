/*
Problem Statement #
Given a string, we want to cut it into pieces such that each piece is a
palindrome. Write a function to return the minimum number of cuts needed.

Example 1:

Input: "abdbca"
Output: 3
Explanation: Palindrome pieces are "a", "bdb", "c", "a".
Example 2:

Input: = "cddpd"
Output: 2
Explanation: Palindrome pieces are "c", "d", "dpd".
Example 3:

Input: = "pqr"
Output: 2
Explanation: Palindrome pieces are "p", "q", "r".
Example 4:

Input: = "pp"
Output: 0
Explanation: We do not need to cut, as "pp" is a palindrome.


The time complexity of the above algorithm is exponential O(2^n), where ‘n’ is
the length of the input string. The space complexity is O(n) which is used to
store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <string>

class MPP {

public:
  int findMPPCuts(const string &st) { return this->findMPPCutsRecursive(st, 0, st.length() - 1); }

private:
  int findMPPCutsRecursive(const string &st, int startIndex, int endIndex) {
    // we don't need to cut the string if it is a palindrome
    if (startIndex >= endIndex || isPalindrome(st, startIndex, endIndex)) {
      return 0;
    }

    // at max, we need to cut the string into its 'length-1' pieces
    int minimumCuts = endIndex - startIndex;
    for (int i = startIndex; i <= endIndex; i++) {
      if (isPalindrome(st, startIndex, i)) {
        // we can cut here as we have a palindrome from 'startIndex' to 'i'
        minimumCuts = min(minimumCuts, 1 + findMPPCutsRecursive(st, i + 1, endIndex));
      }
    }
    return minimumCuts;
  }

  bool isPalindrome(const string &st, int x, int y) {
    while (x < y) {
      if (st[x++] != st[y--]) {
        return false;
      }
    }
    return true;
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
