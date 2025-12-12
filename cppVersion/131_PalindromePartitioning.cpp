#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<bool>> edges;
  vector<vector<string>> partition(string s) {
    int n = s.size();
    edges = vector(n, vector<bool>(n));
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
