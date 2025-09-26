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
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, unordered_set<int>> nodes;
    for (auto p : prerequisites) {
      int key = p[1];
      int value = p[0];
      // 父节点是key
      nodes[key].insert(value);
    }

    unordered_set<int> visitedNodes;
    deque<int> dq;
    // dq 记录需要遍历的节点
    bool isCourseWorked = true;
    for (auto &kv : nodes) {
      dq = {kv.first};
      visitedNodes = {kv.first};
      while (dq.size() && isCourseWorked) {
        int parent = dq.front();
        visitedNodes.insert(parent);
        // 是否会出现一个节点存在于树中，但是词典没有记录的情况。
        // 可能尾部节点不会被放到unordered_map中但是 如果,
        // 这个叶子节点正好在环上会不会出现错误, 如果这个是实际上的叶子节点,
        // 但是又在环上, 那么说明这个逻辑不存在 因为只要是没有后代节点的节点,
        // 一定不在环上, 因为在环上一定有后代. 那么说这里面的小逻辑还是非常多的
        //
        //
        // 检查是否有任何子节点之前被访问过
        // 一个编码的问题就是, 变量的意义记不清
        for (auto child : nodes[parent]) {
          if (visitedNodes.contains(child)) {
            isCourseWorked = false;
            break;
          }

          dq.push_back(child);
        }
        if (isCourseWorked) {
          dq.pop_front();
          // 这一步是有问题的，对于parent的同级之间, 也可能出现课程依赖关系
          // 这还是对题目没有理解透彻。
          // 但是如果一个一个的添加, 那代码的复杂度急剧上升
          visitedNodes.insert(nodes[parent].begin(), nodes[parent].end());
        }
      }
    }

    return isCourseWorked;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
