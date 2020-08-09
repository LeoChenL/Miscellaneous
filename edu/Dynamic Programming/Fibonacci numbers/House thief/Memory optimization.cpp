/*
time complexity of O(n) and a constant space complexity O(1)
*/

using namespace std;

#include <iostream>
#include <vector>

class HouseThief {
public:
  int findMaxSteal(const vector<int> &wealth) {
    if (wealth.empty()) {
      return 0;
    }
    int n1 = 0, n2 = wealth[0], temp;
    for (int i = 1; i < wealth.size(); i++) {
      temp = max(n1 + wealth[i], n2);
      n1 = n2;
      n2 = temp;
    }
    return n2;
  }
};

int main(int argc, char *argv[]) {
  HouseThief *ht = new HouseThief();
  vector<int> wealth = {2, 5, 1, 3, 6, 2, 4};
  cout << ht->findMaxSteal(wealth) << endl;
  wealth = vector<int>{2, 10, 14, 8, 1};
  cout << ht->findMaxSteal(wealth) << endl;

  delete ht;
}
