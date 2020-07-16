/*
Problem Statement #
Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.

Example 1:

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
Example 2:

Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11
*/

using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
public:
  static pair<int, int> search(const vector<int> &arr, int targetSum) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
      int currentSum = arr[left] + arr[right];
      if (currentSum == targetSum) { // found the pair
        return make_pair(left, right);
      }

      if (targetSum > currentSum)
        left++; // we need a pair with a bigger sum
      else
        right--; // we need a pair with a smaller sum
    }
    return make_pair(-1, -1);
  }
};

int main(int argc, char *argv[]) {
  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
}

// An Alternate approach hashtable
// using namespace std;
//
// #include <iostream>
// #include <unordered_map>
// #include <vector>
//
// class PairWithTargetSum {
//  public:
//   static pair<int, int> search(const vector<int>& arr, int targetSum) {
//     unordered_map<int, int> nums;  // to store number and its index
//     for (int i = 0; i < arr.size(); i++) {
//       if (nums.find(targetSum - arr[i]) != nums.end()) {
//         return make_pair(nums[targetSum - arr[i]], i);
//       } else {
//         nums[arr[i]] = i;  // put the number and its index in the map
//       }
//     }
//     return make_pair(-1, -1);  // pair not found
//   }
// };
//
// int main(int argc, char* argv[]) {
//   auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
//   cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
//   result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
//   cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
// }
