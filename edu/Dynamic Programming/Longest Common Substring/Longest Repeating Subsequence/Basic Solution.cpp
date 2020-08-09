/*
Problem Statement #
Given a sequence, find the length of its longest repeating subsequence (LRS).
A repeating subsequence will be the one that appears at least twice in the
original sequence and is not overlapping (i.e. none of the corresponding
characters in the repeating subsequences have the same index).

Example 1:

Input: “t o m o r r o w”
Output: 2
Explanation: The longest repeating subsequence is “or” {tomorrow}.

Example 2:

Input: “a a b d b c e c”
Output: 3
Explanation: The longest repeating subsequence is “a b c” {a a b d b c e c}.

Example 3:

Input: “f m f f”
Output: 2
Explanation: The longest repeating subsequence is “f f” {f m f f, f m f f}.
Please note the second last character is shared in LRS.


The time complexity of the above algorithm is exponential O(2^n), where ‘n’ is
the length of the input sequence. The space complexity is O(n) which is used to
store the recursion stack.
*/


using namespace std;

#include <iostream>
#include <string>

class LRS {

public:
  int findLRSLength(const string &str) { return findLRSLengthRecursive(str, 0, 0); }

private:
  int findLRSLengthRecursive(const string &str, int i1, int i2) {
    if (i1 == str.length() || i2 == str.length()) {
      return 0;
    }

    if (i1 != i2 && str[i1] == str[i2]) {
      return 1 + findLRSLengthRecursive(str, i1 + 1, i2 + 1);
    }

    int c1 = findLRSLengthRecursive(str, i1, i2 + 1);
    int c2 = findLRSLengthRecursive(str, i1 + 1, i2);

    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LRS *lrs = new LRS();
  cout << lrs->findLRSLength("tomorrow") << endl;
  cout << lrs->findLRSLength("aabdbcec") << endl;
  cout << lrs->findLRSLength("fmff") << endl;

  delete lrs;
}
