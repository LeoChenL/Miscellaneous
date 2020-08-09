/*
The above solution has time and space complexity of O(L*N), where ‘L’ 
represents total ribbon lengths and ‘N’ is the total length that we want to cut.
*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CutRibbon {

public:
  int countRibbonPieces(const vector<int> &ribbonLengths, int total) {
    int n = ribbonLengths.size();
    vector<vector<int>> dp(n, vector<int>(total + 1));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= total; j++) {
        dp[i][j] = numeric_limits<int>::min();
      }
    }

    // populate the total=0 columns, as we don't need any ribbon to make zero total
    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }

    for (int i = 0; i < n; i++) {
      for (int t = 1; t <= total; t++) {
        if (i > 0) // exclude the ribbon
        {
          dp[i][t] = dp[i - 1][t];
        }
        // include the ribbon and check if the remaining length can be cut into available lengths
        if (t >= ribbonLengths[i] && dp[i][t - ribbonLengths[i]] != numeric_limits<int>::min()) {
          dp[i][t] = max(dp[i][t], dp[i][t - ribbonLengths[i]] + 1);
        }
      }
    }

    // total combinations will be at the bottom-right corner, return '-1' if cutting is not possible
    return (dp[n - 1][total] == numeric_limits<int>::min() ? -1 : dp[n - 1][total]);
  }
};

int main(int argc, char *argv[]) {
  CutRibbon *cr = new CutRibbon();
  vector<int> ribbonLengths = {2, 3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 5) << endl;
  ribbonLengths = vector<int>{2, 3};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;
  ribbonLengths = vector<int>{5, 3, 7};
  cout << cr->countRibbonPieces(ribbonLengths, 13) << endl;
  ribbonLengths = vector<int>{3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;

  delete cr;
}
