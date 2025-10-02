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
  bool dfs(int curNode, unordered_set<int> &curPath,
           unordered_set<int> &checkedNodes,
           unordered_map<int, unordered_set<int>> &nodes) {
    if (checkedNodes.contains(curNode))
      return true;
    else if (find(curPath.begin(), curPath.end(), curNode) != curPath.end())
      return false;
    curPath.insert(curNode);
    for (auto &child : nodes[curNode]) {
      if (!dfs(child, curPath, checkedNodes, nodes))
        return false;
    }

    checkedNodes.insert(curNode); // 这个位置搞错了, 之前放在上面是不对的
    curPath.erase(curNode);
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

    unordered_set<int> visitedNodesThisTurn;
    unordered_set<int> checkedNodes;
    bool isCourseWorked = true;
    for (auto &kv : nodes) {
      visitedNodesThisTurn.clear();
      if (!dfs(kv.first, visitedNodesThisTurn, checkedNodes, nodes))
        return false;
    }

    return true;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
