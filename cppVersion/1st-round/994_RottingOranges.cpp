#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <deque>
#include <exception>
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

  struct Pos {
    int x;
    int y;
    Pos(int xx, int yy) : x(xx), y(yy) {}
  };

public:
  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int allOrgCnt = 0;
    int rottedOrg = 0;
    int time = 0;
    deque<Pos> dq;
    for (int i = 0; i < m; ++i) {
      for (int k = 0; k < n; ++k) {
        if (grid[i][k] == 2) {
          dq.push_back(Pos(i, k));
          rottedOrg++;
        }
        if (grid[i][k] != 0)
          allOrgCnt++;
      }
    }

    int curCheckCount = rottedOrg;
    int nextCheckCount = 0;
    while (!dq.empty()) {
      nextCheckCount = 0;
      for (int i = 0; i < curCheckCount; ++i) {
        Pos tmp = dq.front();
        if (tmp.x - 1 >= 0 && grid[tmp.x - 1][tmp.y] == 1) {
          grid[tmp.x - 1][tmp.y] = 2;
          rottedOrg++;
          nextCheckCount++;
          dq.push_back(Pos(tmp.x - 1, tmp.y));
        }

        if (tmp.x + 1 < grid.size() && grid[tmp.x + 1][tmp.y] == 1) {
          grid[tmp.x + 1][tmp.y] = 2;
          rottedOrg++;
          nextCheckCount++;
          dq.push_back(Pos(tmp.x + 1, tmp.y));
        }

        if (tmp.y - 1 >= 0 && grid[tmp.x][tmp.y - 1] == 1) {
          grid[tmp.x][tmp.y - 1] = 2;
          rottedOrg++;
          nextCheckCount++;
          dq.push_back(Pos(tmp.x, tmp.y - 1));
        }

        if (tmp.y + 1 < grid[0].size() && grid[tmp.x][tmp.y + 1] == 1) {
          grid[tmp.x][tmp.y + 1] = 2;
          rottedOrg++;
          nextCheckCount++;
          dq.push_back(Pos(tmp.x, tmp.y + 1));
        }

        dq.pop_front();
      }

      curCheckCount = nextCheckCount;

      if (nextCheckCount) // 这个time的计算逻辑是依赖于, 本轮次有橘子被腐烂.
        time++;
    }

    if (rottedOrg == allOrgCnt)
      return time;
    else
      return -1;
  }
};

int main() {
  Solution s;
  cout << "hello" << endl;
}
