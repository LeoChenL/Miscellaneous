/*
Problem Statement #
Given a sequence, find the length of its Longest Palindromic Subsequence (LPS).
In a palindromic subsequence, elements read the same backward and forward.

A subsequence is a sequence that can be derived from another sequence by
deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: "abdbca"
Output: 5
Explanation: LPS is "abdba".
Example 2:

Input: = "cddpd"
Output: 3
Explanation: LPS is "ddd".
Example 3:

Input: = "pqr"
Output: 1
Explanation: LPS could be "p", "q" or "r".


The time complexity of the above algorithm is exponential O(2^n), where ‘n’ is
the length of the input sequence. The space complexity is O(n) which is used to
store the recursion stack.
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

    // every sequence with one element is a palindrome of length 1
    if (startIndex == endIndex) {
      return 1;
    }

    // case 1: elements at the beginning and the end are the same
    if (st[startIndex] == st[endIndex]) {
      return 2 + findLPSLengthRecursive(st, startIndex + 1, endIndex - 1);
    }

    // case 2: skip one element either from the beginning or the end
    int c1 = findLPSLengthRecursive(st, startIndex + 1, endIndex);
    int c2 = findLPSLengthRecursive(st, startIndex, endIndex - 1);
    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}
