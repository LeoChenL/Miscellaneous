/*
Problem Statement #
Given two sequences ‘s1’ and ‘s2’, write a method to find the length of the
shortest sequence which has ‘s1’ and ‘s2’ as subsequences.

Example 2:

Input: s1: "abcf" s2:"bdcf"
Output: 5
Explanation: The shortest common super-sequence (SCS) is "abdcf".
Example 2:

Input: s1: "dynamic" s2:"programming"
Output: 15
Explanation: The SCS is "dynprogrammicng".


The time complexity of the above algorithm is exponential O(2^{n+m}), where ‘n’
and ‘m’ are the lengths of the input sequences. The space complexity is O(n+m)
which is used to store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <string>

class SCS {

public:
  int findSCSLength(const string &s1, const string &s2) {
    return findSCSLengthRecursive(s1, s2, 0, 0);
  }

private:
  int findSCSLengthRecursive(const string &s1, const string &s2, int i1, int i2) {
    // if we have reached the end of a string, return the remaining length of the other string,
    // as in this case we have to take all of the remaining other string
    if (i1 == s1.length()) {
      return s2.length() - i2;
    }
    if (i2 == s2.length()) {
      return s1.length() - i1;
    }

    if (s1[i1] == s2[i2]) {
      return 1 + findSCSLengthRecursive(s1, s2, i1 + 1, i2 + 1);
    }

    int length1 = 1 + findSCSLengthRecursive(s1, s2, i1, i2 + 1);
    int length2 = 1 + findSCSLengthRecursive(s1, s2, i1 + 1, i2);

    return min(length1, length2);
  }
};

int main(int argc, char *argv[]) {
  SCS *scs = new SCS();
  cout << scs->findSCSLength("abcf", "bdcf") << endl;
  cout << scs->findSCSLength("dynamic", "programming") << endl;

  delete scs;
}
