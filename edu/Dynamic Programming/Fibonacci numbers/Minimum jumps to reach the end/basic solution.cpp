/*
vProblem Statement #
Given an array of positive numbers, where each element represents the max
number of jumps that can be made forward from that element, write a program to
find the minimum number of jumps needed to reach the end of the array (starting
from the first element). If an element is 0, then we cannot move through that
element.

Example 1:

Input = {2,1,1,1,4}
Output = 3
Explanation: Starting from index '0', we can reach the last index through:
0->2->3->4
Example 2:

Input = {1,1,3,6,9,3,0,1,3}
Output = 4
Explanation: Starting from index '0', we can reach the last index through:
0->1->2->3->8


The time complexity of the above algorithm is O(2^n), where ‘n’ is the size of
the input array. The ‘while loop’ can execute a maximum of ‘n’ times (for the
case where we can jump to all the steps ahead) and since in each iteration, the
function recursively calls itself, therefore, the time complexity is O(2^n).
The space complexity is O(n) which is used to store the recursion stack.

*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayJump {
public:
  int countMinJumps(const vector<int> &jumps) {
    return this->countMinJumpsRecursive(jumps, 0);
  }

private:
  int countMinJumpsRecursive(const vector<int> &jumps, int currentIndex) {
    // if we have reached the last index, we don't need any more jumps
    if (currentIndex == jumps.size() - 1) {
      return 0;
    }

    if (jumps[currentIndex] == 0) {
      return numeric_limits<int>::max();
    }

    int totalJumps = numeric_limits<int>::max();
    int start = currentIndex + 1;
    int end = currentIndex + jumps[currentIndex];
    while (start < jumps.size() && start <= end) {
      // jump one step and recurse for the remaining array
      int minJumps = countMinJumpsRecursive(jumps, start++);
      if (minJumps != numeric_limits<int>::max()) {
        totalJumps = min(totalJumps, minJumps + 1);
      }
    }
    return totalJumps;
  }
};

int main(int argc, char *argv[]) {
  ArrayJump *aj = new ArrayJump();
  vector<int> jumps = {2, 1, 1, 1, 4};
  cout << aj->countMinJumps(jumps) << endl;
  jumps = vector<int>{1, 1, 3, 6, 9, 3, 0, 1, 3};
  cout << aj->countMinJumps(jumps) << endl;

  delete aj;
}
