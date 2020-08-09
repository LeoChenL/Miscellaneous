/*
Problem Statement #
Given two strings ‘s1’ and ‘s2’, find the length of the longest subsequence
which is common in both the strings.

A subsequence is a sequence that can be derived from another sequence by
deleting some or no elements without changing the order of the remaining
elements.

Example 1:

Input: s1 = "abdca"
       s2 = "cbda"
Output: 3
Explanation: The longest common subsequence is "bda".
Example 2:

Input: s1 = "passport"
       s2 = "ppsspt"
Output: 5
Explanation: The longest common subsequence is "psspt".


The time complexity of the above algorithm is exponential O(2^{m+n}), where ‘m’
and ‘n’ are the lengths of the two input strings. The space complexity is O(n+m)
which is used to store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <string>

class LCS {
public:
  int findLCSLength(const string &s1, const string &s2) {
    return findLCSLengthRecursive(s1, s2, 0, 0);
  }

private:
  int findLCSLengthRecursive(const string &s1, const string &s2, int i1, int i2) {
    if (i1 == s1.length() || i2 == s2.length()) {
      return 0;
    }

    if (s1[i1] == s2[i2]) {
      return 1 + findLCSLengthRecursive(s1, s2, i1 + 1, i2 + 1);
    }
    int c1 = findLCSLengthRecursive(s1, s2, i1, i2 + 1);
    int c2 = findLCSLengthRecursive(s1, s2, i1 + 1, i2);
    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  LCS *lcs = new LCS();
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;

  delete lcs;
}
