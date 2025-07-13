#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    // 把一个二维vector根据第一个元素的大小排序, 如果第一个元素的大小相同,
    // 那么根据 第二个元素 减去 第一个元素的大小继续排序
    // 自定义排序函数
    auto customSort = [](const std::vector<int> &a, const std::vector<int> &b) {
      int lenA = a[1] - a[0]; // 计算向量长度
      int lenB = b[1] - b[0];

      // 首先按长度排序
      if (lenA != lenB) {
        return a[0] < b[0]; // 起始值从小到大
      }
      // 长度相同则按起始值排序
      return lenA < lenB; // 长度从小到大
    };

    // 执行排序
    std::sort(events.begin(), events.end(), customSort);
    int result = 0;
    unordered_set<int> usedDays;
    for (auto v : events) {
      for (auto n : v) {
        cout << n << ", ";
      }
      cout << endl;
      for (int n = v.front(); n <= v.back(); n++) {
        if (usedDays.find(n) == usedDays.end()) {
          usedDays.insert(n);
          cout << "insert: " << n << endl;
          result++;
          break;
        } else {
          cout << n << " not in" << endl;
        }
      }
    }

    return result;
  }
};
int main() {
  Solution s;
  vector<vector<int>> n = {{1, 5}, {1, 5}, {1, 2}, {1, 3},
                           {3, 4}, {1, 2}, {1, 4}};
  // vector<vector<int>> n = {{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
  // vector<vector<int>> n = {{1, 3}, {1, 3}, {1, 3}, {3, 4}};
  cout << s.maxEvents(n) << endl;
}
