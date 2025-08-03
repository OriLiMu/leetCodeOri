#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  void func(int start, vector<int> &curSelected, vector<int> &candidates,
            vector<vector<int>> &r, int &sum, int &target) {
    if (sum == target) {
      r.push_back(curSelected);
      return;
    }
    for (int i = start; i < candidates.size(); i++) {
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {}
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
