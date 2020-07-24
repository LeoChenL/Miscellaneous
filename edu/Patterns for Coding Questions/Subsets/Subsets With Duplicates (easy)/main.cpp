/*
Problem Statement #
Given a set of numbers that might contain duplicates, find all of its distinct
subsets.

Example 1:

Input: [1, 3, 3]
Output: [], [1], [3], [1,3], [3,3], [1,3,3]
Example 2:

Input: [1, 5, 3, 3]
Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], [3,3], [1,3,3],
[3,3,5], [1,5,3,3]


Time complexity #
Since, in each step, the number of subsets could double (if not duplicate) as we
add each element to all the existing subsets, the time complexity of the above
algorithm is O(2^N), where ‘N’ is the total number of elements in the input set.
This also means that, in the end, we will have a total of O(2^N) subsets at the
most.

Space complexity #
All the additional space used by our algorithm is for the output list. Since at
most we will have a total of O(2^N) subsets, the space complexity of our
algorithm is also O(2^N).
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // sort the numbers to handle duplicates
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
      startIndex = 0;
      // if current and the previous elements are same, create new subsets only from the subsets
      // added in the previous step
      if (i > 0 && nums[i] == nums[i - 1]) {
        startIndex = endIndex + 1;
      }
      endIndex = subsets.size() - 1;
      for (int j = startIndex; j <= endIndex; j++) {
        // create a new subset from the existing subset and add the current element to it
        vector<int> set(subsets[j]);
        set.push_back(nums[i]);
        subsets.push_back(set);
      }
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
