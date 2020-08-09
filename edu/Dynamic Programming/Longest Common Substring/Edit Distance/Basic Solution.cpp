/*
Problem Statement #
Given strings s1 and s2, we need to transform s1 into s2 by deleting,
inserting, or replacing characters. Write a function to calculate the count of
the minimum number of edit operations.

Example 1:

Input: s1 = "bat"
       s2 = "but"
Output: 1
Explanation: We just need to replace 'a' with 'u' to transform s1 to s2.
Example 2:

Input: s1 = "abdca"
       s2 = "cbda"
Output: 2
Explanation: We can replace first 'a' with 'c' and delete second 'c'.
Example 3:

Input: s1 = "passpot"
       s2 = "ppsspqrt"
Output: 3
Explanation: Replace 'a' with 'p', 'o' with 'q', and insert 'r'.


Because of the three recursive calls, the time complexity of the above algorithm
is exponential O(3^{m+n}), where ‘m’ and ‘n’ are the lengths of the two input
strings. The space complexity is O(n+m) which is used to store the recursion
stack.
*/

using namespace std;

#include <iostream>
#include <string>

class EditDistance {

public:
  int findMinOperations(const string &s1, const string &s2) {
    return findMinOperationsRecursive(s1, s2, 0, 0);
  }

private:
  int findMinOperationsRecursive(const string &s1, const string &s2, int i1, int i2) {

    // if we have reached the end of s1, then we have to insert all the remaining characters of s2
    if (i1 == s1.length()) {
      return s2.length() - i2;
    }

    // if we have reached the end of s2, then we have to delete all the remaining characters of s1
    if (i2 == s2.length()) {
      return s1.length() - i1;
    }

    // If the strings have a matching character, we can recursively match for the remaining lengths
    if (s1[i1] == s2[i2]) {
      return findMinOperationsRecursive(s1, s2, i1 + 1, i2 + 1);
    }

    int c1 = 1 + findMinOperationsRecursive(s1, s2, i1 + 1, i2);     // perform deletion
    int c2 = 1 + findMinOperationsRecursive(s1, s2, i1, i2 + 1);     // perform insertion
    int c3 = 1 + findMinOperationsRecursive(s1, s2, i1 + 1, i2 + 1); // perform replacement

    return min(c1, min(c2, c3));
  }
};

int main(int argc, char *argv[]) {
  EditDistance *editDisatnce = new EditDistance();
  cout << editDisatnce->findMinOperations("bat", "but") << endl;
  cout << editDisatnce->findMinOperations("abdca", "cbda") << endl;
  cout << editDisatnce->findMinOperations("passpot", "ppsspqrt") << endl;

  delete editDisatnce;
}
