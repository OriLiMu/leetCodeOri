#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  struct valueWithIndex {
    int value;
    int index;
  };

public:
  int maxDistance(vector<vector<int>> &arrays) {
    valueWithIndex min1;
    valueWithIndex min2;
    valueWithIndex max1;
    valueWithIndex max2;
    if (arrays[0].front() < arrays[1].front()) {
      min1 = {arrays[0].front(), 0};
      min2 = {arrays[1].front(), 1};
    } else {
      min2 = {arrays[0].front(), 0};
      min1 = {arrays[1].front(), 1};
    }

    if (arrays[0].back() > arrays[1].back()) {
      max1 = {arrays[0].back(), 0};
      max2 = {arrays[1].back(), 1};
    } else {
      max2 = {arrays[0].back(), 0};
      max1 = {arrays[1].back(), 1};
    }
    for (int i = 2; i < arrays.size(); i++) {
      int minTmp = arrays[i].front();
      int maxTmp = arrays[i].back();
      if (minTmp < min1.value) {
        min2 = min1; // 将 min1 的值赋给 min2
        min1.value = minTmp;
        min1.index = i;
      } else if (minTmp < min2.value) {
        min2.value = minTmp;
        min2.index = i;
      }

      if (maxTmp > max1.value) {
        max2 = max1;
        max1.value = maxTmp;
        max1.index = i;
      } else if (maxTmp > max2.value) {
        max2.value = maxTmp;
        max2.index = i;
      }
    }

    if (max1.index != min1.index) {
      return max1.value - min1.value;
    }
    return max(max1.value - min2.value, max2.value - min1.value);
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {{1, 4}, {0, 5}};
  cout << s.maxDistance(v) << endl;
}
