// 18ms beat 70%
#include <cstddef>
#include <vector>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    string result = "";
    int columnNum = (s.size() / (2 * numRows - 2) + 1) * 2;
    vector<vector<char>> ZigzagMatrix(numRows, vector<char>(columnNum, '0'));
    // 找规律, 这个是有周期性的数字
    // 如果 第一个数字 的下标是 i,j; i+1,j; ... i + numRows - 1, j;
    // i + numRows, j + 1; ... ; i + 1, j + numRows - 2;
    // 这里需要考虑斜的哪个部分数字不够的情况, 也就是两行的情况
    int curIndex = 0;
    int curX = 0;
    int curY = 0;
    while (curIndex < s.size()) {
      for (size_t i = 0; i < numRows && curIndex < s.size(); i++) {
        ZigzagMatrix[curX][curY] = s[curIndex++];
        curX++;
      }
      curX--;
      curY++;
      for (size_t i = 0; i < numRows - 2 && curIndex < s.size(); i++) {
        ZigzagMatrix[curX][curY] = s[curIndex++];
        curX--;
        curY++;
      }
    }
    for (size_t i = 0; i < numRows; i++) {
      for (size_t j = 0; j < columnNum; j++) {
        if (ZigzagMatrix[i][j] != '0') {
          s += ZigzagMatrix[i][j];
        }
      }
    }

    return result;
  }
};

int main() { return 0; }
