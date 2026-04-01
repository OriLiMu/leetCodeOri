#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> result;
    result.push_back(1);
    for (int i = 1; i < rowIndex + 1; i++) {
      result.push_back(1LL * result[i - 1] * (rowIndex - i + 1) /
                       i); // 大数计算 1LL
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> result = s.getRow(3);
  cout << "this is the test" << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}
