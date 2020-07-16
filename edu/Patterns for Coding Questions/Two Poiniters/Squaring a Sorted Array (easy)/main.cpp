/*
Problem Statement #
Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9]
*/

using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    int highestSquareIdx = n - 1;
    int left = 0, right = n - 1;
    while (left <= right) {
      int leftSquare = arr[left] * arr[left];
      int rightSquare = arr[right] * arr[right];
      if (leftSquare > rightSquare) {
        squares[highestSquareIdx--] = leftSquare;
        left++;
      } else {
        squares[highestSquareIdx--] = rightSquare;
        right--;
      }
    }
    return squares;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
