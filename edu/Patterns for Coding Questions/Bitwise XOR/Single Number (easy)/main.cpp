/*
Problem Statement #
In a non-empty array of integers, every number appears twice except for one,
find that single number.

Example 1

Input 1, 4, 2, 1, 3, 2, 3
Output 4
Example 2

Input 7, 9, 7
Output 9

Time Complexity: Time complexity of this solution is O(n) as we iterate through
all numbers of the input once.

Space Complexity: The algorithm runs in constant space O(1).
*/

using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      int num = 0;
      for (int i=0; i < arr.size(); i++) {
        num = num ^ arr[i];
      }
      return num;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}
