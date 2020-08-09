/*
Introduction #
We are given a ribbon of length ‘n’ and a set of possible ribbon lengths. Now we
need to cut the ribbon into the maximum number of pieces that comply with the
above-mentioned possible lengths. Write a method that will return the count of
pieces.

Example 1:

n: 5
Ribbon Lengths: {2,3,5}
Output: 2
Explanation: Ribbon pieces will be {2,3}.
Example 2:

n: 7
Ribbon Lengths: {2,3}
Output: 3
Explanation: Ribbon pieces will be {2,2,3}.
Example 3:

n: 13
Ribbon Lengths: {3,5,7}
Output: 3
Explanation: Ribbon pieces will be {3,3,7}.
Problem Statement #
Given a number array to represent possible ribbon lengths and a total ribbon
length ‘n’, we need to find the maximum number of pieces that the ribbon can be
cut into.

This problem follows the Unbounded Knapsack pattern and is quite similar to
Minimum Coin Change (MCC). The only difference is that in MCC we were asked to
find the minimum number of coin changes, whereas in this problem we need to find the maximum number of pieces.


The time complexity of the above algorithm is exponential O(2^{L+T}), where ‘L’
represents total ribbon lengths and ‘N’ is the total length that
we want to cut. The space complexity will be O(L+T).
*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CutRibbon {

public:
  int countRibbonPieces(const vector<int> &ribbonLengths, int total) {
    int maxPieces = this->countRibbonPiecesRecursive(ribbonLengths, total, 0);
    return maxPieces == numeric_limits<int>::min() ? -1 : maxPieces;
  }

private:
  int countRibbonPiecesRecursive(const vector<int> &ribbonLengths, int total, int currentIndex) {
    // base check
    if (total == 0) {
      return 0;
    }

    if (ribbonLengths.empty() || currentIndex >= ribbonLengths.size()) {
      return numeric_limits<int>::min();
    }

    // recursive call after selecting the ribbon length at the currentIndex
    // if the ribbon length at the currentIndex exceeds the total, we shouldn't process this
    int c1 = numeric_limits<int>::min();
    if (ribbonLengths[currentIndex] <= total) {
      int result = countRibbonPiecesRecursive(ribbonLengths, total - ribbonLengths[currentIndex],
                                              currentIndex);
      if (result != numeric_limits<int>::min()) {
        c1 = result + 1;
      }
    }

    // recursive call after excluding the ribbon length at the currentIndex
    int c2 = countRibbonPiecesRecursive(ribbonLengths, total, currentIndex + 1);
    return max(c1, c2);
  }
};

int main(int argc, char *argv[]) {
  CutRibbon *cr = new CutRibbon();
  vector<int> ribbonLengths = {2, 3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 5) << endl;
  ribbonLengths = vector<int>{2, 3};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;
  ribbonLengths = vector<int>{3, 5, 7};
  cout << cr->countRibbonPieces(ribbonLengths, 13) << endl;
  ribbonLengths = vector<int>{3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;

  delete cr;
}
