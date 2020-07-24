using namespace std;

#include <iostream>
#include <vector>

class PermutationsRecursive {
 public:
  static vector<vector<int>> generatePermutations(const vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> currentPermutation;
    generatePermutationsRecursive(nums, 0, currentPermutation, result);
    return result;
  }

 private:
  static void generatePermutationsRecursive(const vector<int> &nums, int index,
                                      vector<int> &currentPermutation, vector<vector<int>> &result) {
    if (index == nums.size()) {
      result.push_back(currentPermutation);
    } else {
      // create a new permutation by adding the current number at every position
      for (int i = 0; i <= currentPermutation.size(); i++) {
        vector<int> newPermutation(currentPermutation);
        newPermutation.insert(newPermutation.begin() + i, nums[index]);
        generatePermutationsRecursive(nums, index + 1, newPermutation, result);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> result = PermutationsRecursive::generatePermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
