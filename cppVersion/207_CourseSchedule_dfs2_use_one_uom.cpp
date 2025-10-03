#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <deque>
#include <execution>
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
  // 这个方法合并1 的 curPath 和 checkedNodes 到一个
  // 每次一个路径走完之后, 要么中途发现无效点, 要么回来所有点都是有效点
  bool dfs(int curNode, unordered_map<int, int> &nodeStatus,
           unordered_map<int, unordered_set<int>> &nodes) {
    if (nodeStatus.contains(curNode)) {
      if (nodeStatus[curNode] == 0)
        return false;
      else
        return true;
    }
    nodeStatus[curNode] = 0;
    for (auto &child : nodes[curNode]) {
      if (!dfs(child, nodeStatus, nodes))
        return false;
    }

    nodeStatus[curNode] = 1;
    return true;
  }
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, unordered_set<int>> nodes;
    for (auto p : prerequisites) {
      int key = p[1];
      int value = p[0];
      // 父节点是key
      nodes[key].insert(value);
    }

    unordered_map<int, int> nodeStatus;
    bool isCourseWorked = true;
    for (auto &kv : nodes) {
      if (!dfs(kv.first, nodeStatus, nodes))
        return false;
    }

    return true;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
