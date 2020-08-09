
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class SI {

public:
  bool findSI(const string &m, const string &n, const string &p) {
    unordered_map<string, bool> dp;
    return findSIRecursive(dp, m, n, p, 0, 0, 0);
  }

private:
  bool findSIRecursive(unordered_map<string, bool> &dp, const string &m, const string &n,
                       const string &p, int mIndex, int nIndex, int pIndex) {

    // if we have reached the end of the all the strings
    if (mIndex == m.length() && nIndex == n.length() && pIndex == p.length()) {
      return true;
    }

    // if we have reached the end of 'p' but 'm' or 'n' still has some characters
    // left
    if (pIndex == p.length()) {
      return false;
    }

    string subProblemKey = to_string(mIndex) + "-" + to_string(nIndex) + "-" + to_string(pIndex);
    if (dp.find(subProblemKey) == dp.end()) {
      bool b1 = false, b2 = false;
      if (mIndex < m.length() && m[mIndex] == p[pIndex]) {
        b1 = findSIRecursive(dp, m, n, p, mIndex + 1, nIndex, pIndex + 1);
      }

      if (nIndex < n.length() && n[nIndex] == p[pIndex]) {
        b2 = findSIRecursive(dp, m, n, p, mIndex, nIndex + 1, pIndex + 1);
      }

      dp.emplace(subProblemKey, b1 || b2);
    }

    return dp[subProblemKey];
  }
};

int main(int argc, char *argv[]) {
  SI *si = new SI();
  cout << si->findSI("abd", "cef", "abcdef") << endl;
  cout << si->findSI("abd", "cef", "adcbef") << endl;
  cout << si->findSI("abc", "def", "abdccf") << endl;
  cout << si->findSI("abcdef", "mnop", "mnaobcdepf") << endl;

  delete si;
}
