#include <climits>
#include <cmath>
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
public:
  int func(int n, vector<int> &v) {
    // cout << n << endl;
    if (v[n] != -1)
      return v[n];
    int e = sqrt(n);
    int r = INT_MAX;
    for (int i = 1; i <= e; i++)
      r = min(r, func(n - i * i, v) + 1);
    v[n] = r;
    return r;
  }
  int numSquares(int n) {
    vector<int> v(n + 1, -1);
    v[0] = 0;
    return func(n, v);
  }
};

int main() {
  Solution s;
  int n = 12;
  cout << s.numSquares(n) << endl;
}
