#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <deque>
#include <execution>
#include <iostream>
#include <iterator>
#include <oneapi/tbb/partitioner.h>
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
  bool dfs(int curNode, vector<int> &nodeStatus, vector<vector<int>> &nodes) {
    if (nodeStatus[curNode] == 1)
      return false;
    else if (nodeStatus[curNode] == 2)
      return true;

    nodeStatus[curNode] = 1;
    for (auto &child : nodes[curNode]) {
      if (!dfs(child, nodeStatus, nodes))
        return false;
    }

    nodeStatus[curNode] = 2;
    return true;
  }
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> nodes(numCourses);
    for (auto p : prerequisites) {
      int key = p[1];
      int value = p[0];
      // 父节点是key
      nodes[key].push_back(value);
    }

    vector<int> nodeStatus(numCourses, 0);
    for (int i = 0; i < nodes.size(); ++i) {
      if (nodes[i].size())
        if (!dfs(i, nodeStatus, nodes))
          return false;
    }
    return true;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
