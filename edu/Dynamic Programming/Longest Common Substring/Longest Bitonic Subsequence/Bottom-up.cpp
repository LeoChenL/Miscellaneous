/*
The time complexity of the above algorithm is O(n^2) and the space complexity is O(n).
*/

using namespace std;

#include <iostream>
#include <vector>

class LBS {
public:
  int findLBSLength(const vector<int> &nums) {
    vector<int> lds(nums.size());
    vector<int> ldsReverse(nums.size());

    // find LDS for every index up to the beginning of the array
    for (int i = 0; i < nums.size(); i++) {
      lds[i] = 1; // every element is an LDS of length 1
      for (int j = i - 1; j >= 0; j--) {
        if (nums[j] < nums[i]) {
          lds[i] = max(lds[i], lds[j] + 1);
        }
      }
    }

    // find LDS for every index up to the end of the array
    for (int i = nums.size() - 1; i >= 0; i--) {
      ldsReverse[i] = 1; // every element is an LDS of length 1
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] < nums[i]) {
          ldsReverse[i] = max(ldsReverse[i], ldsReverse[j] + 1);
        }
      }
    }

    int maxLength = 0;
    for (int i = 0; i < nums.size(); i++) {
      maxLength = max(maxLength, lds[i] + ldsReverse[i] - 1);
    }

    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  LBS *lbs = new LBS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lbs->findLBSLength(nums) << endl;
  nums = vector<int>{4, 2, 5, 9, 7, 6, 10, 3, 1};
  cout << lbs->findLBSLength(nums) << endl;

  delete lbs;
}
