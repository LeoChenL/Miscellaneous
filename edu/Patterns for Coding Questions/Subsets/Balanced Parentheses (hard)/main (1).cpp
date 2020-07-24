using namespace std;

#include <iostream>
#include <string>
#include <vector>

class GenerateParenthesesRecursive {
 public:
  static vector<string> generateValidParentheses(int num) {
    vector<string> result;
    vector<char> parenthesesString(2 * num);
    generateValidParenthesesRecursive(num, 0, 0, parenthesesString, 0, result);
    return result;
  }

 private:
  static void generateValidParenthesesRecursive(int num, int openCount, int closeCount,
                                                vector<char> &parenthesesString, int index,
                                                vector<string> &result) {
    // if we've reached the maximum number of open and close parentheses, add to the result
    if (openCount == num && closeCount == num) {
      result.push_back(string(parenthesesString.begin(), parenthesesString.end()));
    } else {
      if (openCount < num) {  // if we can add an open parentheses, add it
        parenthesesString[index] = '(';
        generateValidParenthesesRecursive(num, openCount + 1, closeCount, parenthesesString,
                                          index + 1, result);
      }

      if (openCount > closeCount) {  // if we can add a close parentheses, add it
        parenthesesString[index] = ')';
        generateValidParenthesesRecursive(num, openCount, closeCount + 1, parenthesesString,
                                          index + 1, result);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GenerateParenthesesRecursive::generateValidParentheses(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParenthesesRecursive::generateValidParentheses(3);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
