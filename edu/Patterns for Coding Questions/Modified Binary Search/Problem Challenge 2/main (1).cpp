/*
Problem 1 #
How do we search in a sorted and rotated array that also has duplicates?

The code above will fail in the following example!

Example 1:

Input: [3, 7, 3, 3, 3], key = 7
Output: 1
Explanation: '7' is present in the array at index '1'.


Time complexity #
This algorithm will run most of the times in O(logN). However, since we only
skip two numbers in case of duplicates instead of half of the numbers, the worst
case time complexity will become O(N).

Space complexity #
The algorithm runs in constant space O(1).
*/

using namespace std;

#include <iostream>
#include <vector>

class SearchRotatedWithDuplicate {
 public:
  static int search(const vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key) {
        return mid;
      }

      // the only difference from the previous solution,
      // if numbers at indexes start, mid, and end are same, we can't choose a side
      // the best we can do, is to skip one number from both ends as key != arr[mid]
      if ((arr[start] == arr[mid]) && (arr[end] == arr[mid])) {
        ++start;
        --end;
      } else if (arr[start] <= arr[mid]) {  // left side is sorted in ascending order
        if (key >= arr[start] && key < arr[mid]) {
          end = mid - 1;
        } else {  // key > arr[mid]
          start = mid + 1;
        }
      } else {  // right side is sorted in ascending order
        if (key > arr[mid] && key <= arr[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }

    // we are not able to find the element in the given array
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedWithDuplicate::search(vector<int>{3, 7, 3, 3, 3}, 7) << endl;
}
