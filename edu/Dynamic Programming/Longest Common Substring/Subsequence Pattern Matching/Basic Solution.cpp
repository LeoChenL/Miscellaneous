/*
Problem Statement #
Given a string and a pattern, write a method to count the number of times the
pattern appears in the string as a subsequence.

Example 1: Input: string: “baxmx”, pattern: “ax”
Output: 2
Explanation: {baxmx, baxmx}.

Example 2:

Input: string: “tomorrow”, pattern: “tor”
Output: 4
Explanation: Following are the four occurences: {tomorrow, tomorrow, tomorrow,
tomorrow}.


The time complexity of the above algorithm is exponential O(2^{m}), where ‘m’
is the length of the string, as our recursion stack will not be deeper than m.
The space complexity is O(m) which is used to store the recursion stack.
*/

using namespace std;

#include <iostream>
#include <string>

class SPM {
public:
  int findSPMCount(const string &str, const string &pat) {
    return findSPMCountRecursive(str, pat, 0, 0);
  }

private:
  int findSPMCountRecursive(const string &str, const string &pat, int strIndex, int patIndex) {

    // if we have reached the end of the pattern
    if (patIndex == pat.length()) {
      return 1;
    }
    // if we have reached the end of the string but pattern has still some characters left
    if (strIndex == str.length()) {
      return 0;
    }
    int c1 = 0;
    if (str[strIndex] == pat[patIndex]) {
      c1 = findSPMCountRecursive(str, pat, strIndex + 1, patIndex + 1);
    }

    int c2 = findSPMCountRecursive(str, pat, strIndex + 1, patIndex);
    return c1 + c2;
  }
};

int main(int argc, char *argv[]) {
  SPM *spm = new SPM();
  cout << spm->findSPMCount("baxmx", "ax") << endl;
  cout << spm->findSPMCount("tomorrow", "tor") << endl;

  delete spm;
}
