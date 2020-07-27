/*
Rotation Count (medium) #
Given an array of numbers which is sorted in ascending order and is rotated ‘k’ times around a pivot, find ‘k’.

You can assume that the array does not have any duplicates.

Example 1:
Input: [10, 15, 1, 3, 8]
Output: 2

Example 2:
Input: [4, 5, 7, 9, 10, -1, 2]
Output: 5

Example 3:
Input: [1, 3, 8, 10]
Output: 0
Explanation: The array has not been rotated.

Time complexity #
Since we are reducing the search range by half at every step, this means that
the time complexity of our algorithm will be O(logN) where ‘N’ is the total
elements in the given array.

Space complexity #
The algorithm runs in constant space O(1).
*/

using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
      int mid = start + (end - start) / 2;

      if (mid < end && arr[mid] > arr[mid + 1]) {  // if mid is greater than the next element
        return mid + 1;
      }
      if (mid > start && arr[mid - 1] > arr[mid]) {  // if mid is smaller than the previous element
        return mid;
      }

      if (arr[start] < arr[mid]) {  // left side is sorted, so the pivot is on right side
        start = mid + 1;
      } else {  // right side is sorted, so the pivot is on the left side
        end = mid - 1;
      }
    }

    return 0;  // the array has not been rotated
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}
