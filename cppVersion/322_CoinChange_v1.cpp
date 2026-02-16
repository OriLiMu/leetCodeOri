#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> v(amount + 1, amount + 1);
    v[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (auto c : coins)
        if (i >= c)
          v[i] = min(v[i], v[i - c] + 1);
    }

    return v.back() == amount + 1 ? -1 : v.back();
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 5};
  int amount = 11;
  v = {2};
  amount = 3;
  v = {2, 5, 10, 1};
  amount = 27;
  cout << s.coinChange(v, amount) << endl;
}
