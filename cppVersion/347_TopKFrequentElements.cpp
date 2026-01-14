#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <ranges>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> um;
    struct cmp {
      bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
      };
    };
    for (auto &n : nums)
      um[n]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<int> r;
    return r;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
