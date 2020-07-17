/*
Problem Statement #
Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.

Example 1:
Input: 23
Output: true (23 is a happy number)
2x​2​​ + 3x3 = 4 + 9 = 13
1x1 + 3x3 = 1 + 9 = 10
1x1 + 0x0​ = 1 + 0 = 1

Example 2:
Input: 12
Output: false (12 is not a happy number)
*/

using namespace std;

#include <iostream>
#include <unordered_set>
#include <math.h>


class HappyNumber {
 public:
  static bool find(int num) {
    // TODO: Write your code here
    unordered_set<int> memo{num};

    while ( 1 ) {
      num = squareSum(num);
      cout<<"digisum "<< num<< endl;
      if ( num==1 ) {
        return true;
      }
      if (  memo.find(num) != memo.end() ) {
        cout<<"find"<<endl;
        return false;
      }
      memo.insert(num);
    }

    return false;
  }
  static int squareSum(int num) {
    int sum = 0;

    while (num>0) {
      int digit = num%10;
      sum += digit*digit;
      num = floor(num/10);
    }
    return sum;
  }
};

int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}
