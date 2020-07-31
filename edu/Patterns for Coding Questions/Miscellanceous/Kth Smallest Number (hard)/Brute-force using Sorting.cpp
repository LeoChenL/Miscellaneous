/*
Time & Space Complexity #
Sorting will take O(NlogN) and if we are not using an in-place sorting
algorithm, we will need O(N) space.
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[k - 1];
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {1, 5, 12, 2, 11, 5};
  int result = KthSmallestNumber::findKthSmallestNumber(vec, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vec, 4);
  cout << "Kth smallest number is: " << result << endl;

  vec = {5, 12, 11, -1, 12};
  result = KthSmallestNumber::findKthSmallestNumber(vec, 3);
  cout << "Kth smallest number is: " << result << endl;
}
