/*
Count of Structurally Unique Binary Search Trees (hard) #
Given a number ‘n’, write a function to return the count of structurally unique
Binary Search Trees (BST) that can store values 1 to ‘n’.

Example 1:

Input: 2
Output: 2
Explanation: As we saw in the previous problem, there are 2 unique BSTs storing
numbers from 1-2.
Example 2:

Input: 3
Output: 5
Explanation: There will be 5 unique BSTs that can store numbers from 1 to 5.


Time complexity #
The time complexity of this algorithm will be exponential and will be similar to
Balanced Parentheses. Estimated time complexity will be O(n*2^n) but the actual
time complexity ( O(4^n / sqrt{n}) ) is bounded by the Catalan number and is
beyond the scope of a coding interview. See more details here.

Space complexity #
The space complexity of this algorithm will be exponential too, estimated
O(2^n) but the actual will be ( O(4^n / sqrt{n}).
*/

using namespace std;

#include <iostream>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class CountUniqueTrees {
 public:
  int countTrees(int n) {
    if (n <= 1) return 1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
      // making 'i' root of the tree
      int countOfLeftSubtrees = countTrees(i - 1);
      int countOfRightSubtrees = countTrees(n - i);
      count += (countOfLeftSubtrees * countOfRightSubtrees);
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  CountUniqueTrees ct;
  int count = ct.countTrees(3);
  cout << "Total trees: " << count;
}
