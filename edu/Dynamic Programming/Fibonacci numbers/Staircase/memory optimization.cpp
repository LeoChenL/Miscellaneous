/*
a time complexity of O(n) and a constant space complexity O(1)
*/

using namespace std;

#include <iostream>
#include <vector>

class Staircase {

public:
  int CountWays(int n) {
    if (n < 2)
      return 1;
    if (n == 2)
      return 2;
    int n1 = 1, n2 = 1, n3 = 2, temp;
    for (int i = 3; i <= n; i++) {
      temp = n1 + n2 + n3;
      n1 = n2;
      n2 = n3;
      n3 = temp;
    }
    return n3;
  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  cout << sc->CountWays(3) << endl;
  cout << sc->CountWays(4) << endl;
  cout << sc->CountWays(5) << endl;

  delete sc;
}
