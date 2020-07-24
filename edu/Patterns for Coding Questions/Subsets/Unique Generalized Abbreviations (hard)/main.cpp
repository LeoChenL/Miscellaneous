/*
Problem Statement #
Given a word, write a function to generate all of its unique generalized
abbreviations.

Generalized abbreviation of a word can be generated by replacing each substring
of the word by the count of characters in the substring. Take the example of
“ab” which has four substrings: “”, “a”, “b”, and “ab”. After replacing these
substrings in the actual word by the count of characters we get all the
generalized abbreviations: “ab”, “1b”, “a1”, and “2”.

Example 1:

Input: "BAT"
Output: "BAT", "BA1", "B1T", "B2", "1AT", "1A1", "2T", "3"
Example 2:

Input: "code"
Output: "code", "cod1", "co1e", "co2", "c1de", "c1d1", "c2e", "c3", "1ode",
"1od1", "1o1e", "1o2", "2de", "2d1", "3e", "4"


Time complexity #
Since we had two options for each character, we will have a maximum of 2^N
combinations. If you see the visual representation of Example-1 closely you will
realize that it is equivalent to a binary tree, where each node has two children.
This means that we will have 2^N leaf nodes and 2^N - 1intermediate nodes, so
the total number of elements pushed to the queue will be 2^N + 2^N-1, which is
asymptotically equivalent to O(2^N). While processing each element, we do need
to concatenate the current string with a character. This operation will take
O(N), so the overall time complexity of our algorithm will be O(N*2^N)

Space complexity #
All the additional space used by our algorithm is for the output list. Since we
can’t have more than O(2^N) combinations, the space complexity of our algorithm
is O(N*2^N)
*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class AbbreviatedWord {
 public:
  string str;
  int start = 0;
  int count = 0;

  AbbreviatedWord(string str, int start, int count) {
    this->str = str;
    this->start = start;
    this->count = count;
  }
};

class GeneralizedAbbreviation {
 public:
  static vector<string> generateGeneralizedAbbreviation(const string &word) {
    int wordLen = word.length();
    vector<string> result;
    queue<AbbreviatedWord> queue;
    queue.push({"", 0, 0});
    while (!queue.empty()) {
      AbbreviatedWord abWord = queue.front();
      queue.pop();
      if (abWord.start == wordLen) {
        if (abWord.count != 0) {
          abWord.str += to_string(abWord.count);
        }
        result.push_back(abWord.str);
      } else {
        // continue abbreviating by incrementing the current abbreviation count
        queue.push({abWord.str, abWord.start + 1, abWord.count + 1});

        // restart abbreviating, append the count and the current character to the string
        if (abWord.count != 0) {
          abWord.str += to_string(abWord.count);
        }
        abWord.str += word[abWord.start];
        queue.push({abWord.str, abWord.start + 1, 0});
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("BAT");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("code");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
