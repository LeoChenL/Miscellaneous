/*
Problem Statement #
Given a string, find the length of its Longest Palindromic Substring (LPS). In
a palindromic string, elements read the same backward and forward.

Example 1:

Input: "abdbca"
Output: 3
Explanation: LPS is "bdb".
Example 2:

Input: = "cddpd"
Output: 3
Explanation: LPS is "dpd".
Example 3:

Input: = "pqr"
Output: 1
Explanation: LPS could be "p", "q" or "r".


Due to the three recursive calls, the time complexity of the above algorithm is
exponential O(3^n), where ‘n’ is the length of the input string. The space
complexity is O(n) which is used to store the recursion stack.
*/


using namespace std;

#include <iostream>
#include <string>

class LPS {

public:
  int findLPSLength(const string &st) {
    return findLPSLengthRecursive(st, 0, st.length() - 1);
  }

private:
  int findLPSLengthRecursive(const string &st, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
      return 0;
    }

    // every string with one character is a palindrome
    if (startIndex == endIndex) {
      return 1;
    }

    int c1 = 0;
    // case 1: elements at the beginning and the end are the same
    if (st[startIndex] == st[endIndex]) {
      int remainingLength = endIndex - startIndex - 1;
      if (remainingLength == findLPSLengthRecursive(st, startIndex + 1, endIndex - 1)) {
        c1 = remainingLength + 2;
      }
    }

    // case 2: skip one character either from the beginning or the end
    int c2 = findLPSLengthRecursive(st, startIndex + 1, endIndex);
    int c3 = findLPSLengthRecursive(st, startIndex, endIndex - 1);
    return max(c1, max(c2, c3));
  }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}
