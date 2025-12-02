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
  bool func(vector<vector<char>> &board, string &word, string &cur, int r,
            int c, int direction) {
    if (cur == word)
      return true;
    if (direction != 2 && r < board.size())
      func(board, word, cur)
  }
  bool exist(vector<vector<char>> &board, string word) {
    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> accessedMap(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        func(, vector<vector<char>> & board, string & word);
      }
    }
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
