/*
Evaluate Expression (hard) #
Given an expression containing digits and operations (+, -, *), find all
possible ways in which the expression can be evaluated by grouping the numbers
and operators using parentheses.

Example 1:

Input: "1+2*3"
Output: 7, 9
Explanation: 1+(2*3) => 7 and (1+2)*3 => 9
Example 2:

Input: "2*3-4-5"
Output: 8, -12, 7, -7, -3
Explanation: 2*(3-(4-5)) => 8, 2*(3-4-5) => -12, 2*3-(4-5) => 7, 2*(3-4)-5 => -7,
(2*3)-4-5 => -3


Time complexity #
The time complexity of this algorithm will be exponential and will be similar to
Balanced Parentheses. Estimated time complexity will be O(N*2^N) but the actual
time complexity ( O(4^n / sqrt{n}) ) is bounded by the Catalan number and is
beyond the scope of a coding interview. See more details here.

Space complexity #
The space complexity of this algorithm will also be exponential, estimated at
O(2^N) though the actual will be ( O(4^n / sqrt{n}).
*/

using namespace std;

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

class EvaluateExpression {
 public:
  static vector<int> diffWaysToEvaluateExpression(const string& input) {
    vector<int> result;
    // base case: if the input string is a number, parse and add it to output.
    if (input.find("+") == string::npos && input.find("-") == string::npos &&
        input.find("*") == string::npos) {
      result.push_back(stoi(input));
    } else {
      for (int i = 0; i < input.length(); i++) {
        char chr = input[i];
        if (!isdigit(chr)) {
          // break the equation here into two parts and make recursively calls
          vector<int> leftParts = diffWaysToEvaluateExpression(input.substr(0, i));
          vector<int> rightParts = diffWaysToEvaluateExpression(input.substr(i + 1));
          for (auto part1 : leftParts) {
            for (auto part2 : rightParts) {
              if (chr == '+') {
                result.push_back(part1 + part2);
              } else if (chr == '-') {
                result.push_back(part1 - part2);
              } else if (chr == '*') {
                result.push_back(part1 * part2);
              }
            }
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = EvaluateExpression::diffWaysToEvaluateExpression("1+2*3");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = EvaluateExpression::diffWaysToEvaluateExpression("2*3-4-5");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
