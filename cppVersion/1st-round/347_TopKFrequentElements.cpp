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
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (auto &n : nums)
      um[n]++;

    for (auto &pr : um) {
      pq.push(pr);
      if (pq.size() > k)
        pq.pop();
    }

    vector<int> r;
    while (!pq.empty()) {
      auto pr = pq.top();
      r.push_back(pr.first);
      pq.pop();
    }
    return r;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 1, 1, 2, 2, 3};
  v = {1};
  v = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
  int k = 2;
  vector<int> r = s.topKFrequent(v, k);
  for (auto &n : r) {
    cout << n << ", ";
  }
  cout << endl;
}
