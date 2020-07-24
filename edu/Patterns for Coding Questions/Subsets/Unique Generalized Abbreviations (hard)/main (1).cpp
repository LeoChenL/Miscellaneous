using namespace std;

#include <iostream>
#include <string>
#include <vector>

class GeneralizedAbbreviationRecursive {
 public:
  static vector<string> generateGeneralizedAbbreviation(const string &word) {
    vector<string> result;
    string abWord = "";
    generateAbbreviationRecursive(word, abWord, 0, 0, result);
    return result;
  }

 private:
  static void generateAbbreviationRecursive(const string &word, string &abWord, int start,
                                            int count, vector<string> &result) {
    if (start == word.length()) {
      if (count != 0) {
        abWord += to_string(count);
      }
      result.push_back(abWord);
    } else {
      // continue abbreviating by incrementing the current abbreviation count
      string newWord(abWord);
      generateAbbreviationRecursive(word, newWord, start + 1, count + 1, result);

      // restart abbreviating, append the count and the current character to the string
      if (count != 0) {
        abWord += to_string(count);
      }
      abWord += word[start];
      generateAbbreviationRecursive(word, abWord, start + 1, 0, result);
    }
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GeneralizedAbbreviationRecursive::generateGeneralizedAbbreviation("BAT");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GeneralizedAbbreviationRecursive::generateGeneralizedAbbreviation("code");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
