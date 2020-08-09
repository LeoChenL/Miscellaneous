using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class MSIS {

public:
  int findMSIS(const vector<int> &nums) {
    unordered_map<string, int> dp;
    return findMSISRecursive(dp, nums, 0, -1, 0);
  }

private:
  int findMSISRecursive(unordered_map<string, int> &dp, const vector<int> &nums, int currentIndex,
                        int previousIndex, int sum) {
    if (currentIndex == nums.size()) {
      return sum;
    }

    string subProblemKey =
        to_string(currentIndex) + "-" + to_string(previousIndex) + "-" + to_string(sum);
    if (dp.find(subProblemKey) == dp.end()) {
      // include nums[currentIndex] if it is larger than the last included number
      int s1 = sum;
      if (previousIndex == -1 || nums[currentIndex] > nums[previousIndex]) {
        s1 = findMSISRecursive(dp, nums, currentIndex + 1, currentIndex, sum + nums[currentIndex]);
      }

      // excluding the number at currentIndex
      int s2 = findMSISRecursive(dp, nums, currentIndex + 1, previousIndex, sum);
      dp.emplace(subProblemKey, max(s1, s2));
    }

    return dp[subProblemKey];
  }
};

int main(int argc, char *argv[]) {
  MSIS *msis = new MSIS();
  vector<int> nums = {4, 1, 2, 6, 10, 1, 12};
  cout << msis->findMSIS(nums) << endl;
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << msis->findMSIS(nums) << endl;
  nums = vector<int>{1, 3, 8, 4, 14, 6, 14, 1, 9, 4, 13, 3, 11, 17, 29};
  cout << msis->findMSIS(nums) << endl;

  delete msis;
}
