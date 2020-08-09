/*
Problem Statement #
Give three strings ‘m’, ‘n’, and ‘p’, write a method to find out if ‘p’ has
been formed by interleaving ‘m’ and ‘n’. ‘p’ would be considered interleaving
‘m’ and ‘n’ if it contains all the letters from ‘m’ and ‘n’ and the order of
letters is preserved too.

Example 1:

Input: m="abd", n="cef", p="abcdef"
Output: true
Explanation: 'p' contains all the letters from 'm' and 'n' and preserves their
order too.
Example 2:

Input: m="abd", n="cef", p="adcbef"
Output: false
Explanation: 'p' contains all the letters from 'm' and 'n' but does not
preserve the order.
Example 3:

Input: m="abc", n="def", p="abdccf"
Output: false
Explanation: 'p' does not contain all the letters from 'm' and 'n'.
Example 4:

Input: m="abcdef", n="mnop", p="mnaobcdepf"
Output: true
Explanation: 'p' contains all the letters from 'm' and 'n' and preserves their
order too.


The time complexity of the above algorithm is exponential O(2^{m+n}), where ‘m’
and ‘n’ are the lengths of the two interleaving strings. The space complexity
is O(m+n), the value that is used to store the recursion stack.
*/


using namespace std;

#include <iostream>
#include <string>

class SI {

public:
  bool findSI(const string &m, const string &n, const string &p) {
    return findSIRecursive(m, n, p, 0, 0, 0);
  }

private:
  bool findSIRecursive(const string &m, const string &n, const string &p, int mIndex, int nIndex,
                       int pIndex) {

    // if we have reached the end of the all the strings
    if (mIndex == m.length() && nIndex == n.length() && pIndex == p.length()) {
      return true;
    }

    // if we have reached the end of 'p' but 'm' or 'n' still has some characters left
    if (pIndex == p.length()) {
      return false;
    }

    bool b1 = false, b2 = false;
    if (mIndex < m.length() && m[mIndex] == p[pIndex]) {
      b1 = findSIRecursive(m, n, p, mIndex + 1, nIndex, pIndex + 1);
    }

    if (nIndex < n.length() && n[nIndex] == p[pIndex]) {
      b2 = findSIRecursive(m, n, p, mIndex, nIndex + 1, pIndex + 1);
    }

    return b1 || b2;
  }
};

int main(int argc, char *argv[]) {
  SI *si = new SI();
  cout << si->findSI("abd", "cef", "abcdef") << endl;
  cout << si->findSI("abd", "cef", "adcbef") << endl;
  cout << si->findSI("abc", "def", "abdccf") << endl;
  cout << si->findSI("abcdef", "mnop", "mnaobcdepf") << endl;

  delete si;
}
