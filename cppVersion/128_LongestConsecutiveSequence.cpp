#include <iostream>
#include <strings.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> u;
    for (auto &n : nums) {
      bool le = u.contains(n + 1);
      bool re = u.contains(n - 1);
      if (u.contains(le) && u.contains(re)) {
      }
    }
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
