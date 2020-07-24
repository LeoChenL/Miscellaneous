using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class EvaluateExpression {
  // memoization map
 public:
  unordered_map<string, vector<int>> map = unordered_map<string, vector<int>>();

  virtual vector<int> diffWaysToEvaluateExpression(const string& input) {
    if (map.find(input) != map.end()) {
      return map[input];
    }
    vector<int> result;
    // base case: if the input string is a number, parse and return it.
    if (input.find("+") == string::npos && input.find("-") == string::npos &&
        input.find("*") == string::npos) {
      result.push_back(stoi(input));
    } else {
      for (int i = 0; i < input.length(); i++) {
        char chr = input[i];
        if (!isdigit(chr)) {
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
    map[input] = result;
    return result;
  }
};

int main(int argc, char* argv[]) {
  EvaluateExpression ee;
  vector<int> result = ee.diffWaysToEvaluateExpression("1+2*3");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  EvaluateExpression ee1;
  result = ee1.diffWaysToEvaluateExpression("2*3-4-5");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
