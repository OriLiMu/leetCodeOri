#include <chrono>
#include <iostream>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// --- 方案1: 参数传递 ---
class SolutionParams {
public:
  bool dfs(int curNode, std::unordered_set<int> &curPath,
           std::unordered_set<int> &checkedNodes,
           std::unordered_map<int, std::unordered_set<int>> &nodes) {
    if (checkedNodes.contains(curNode))
      return true;
    else if (curPath.contains(curNode))
      return false;

    curPath.insert(curNode);
    for (auto &child : nodes[curNode]) {
      if (!dfs(child, curPath, checkedNodes, nodes))
        return false;
    }

    checkedNodes.insert(curNode);
    curPath.erase(curNode);
    return true;
  }

  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::unordered_map<int, std::unordered_set<int>> nodes;
    for (auto &p : prerequisites) {
      nodes[p[1]].insert(p[0]);
    }

    std::unordered_set<int> curPath;
    std::unordered_set<int> checkedNodes;
    for (auto &kv : nodes) {
      if (!dfs(kv.first, curPath, checkedNodes, nodes))
        return false;
    }
    return true;
  }
};

// --- 方案2: 成员变量 ---
class SolutionMember {
private:
  std::unordered_set<int> checkedNodes;
  std::unordered_map<int, std::unordered_set<int>> nodes;

public:
  bool dfs(int curNode, std::unordered_set<int> &curPath) {
    if (checkedNodes.contains(curNode))
      return true;
    else if (curPath.contains(curNode))
      return false;

    curPath.insert(curNode);
    for (auto &child : nodes[curNode]) {
      if (!dfs(child, curPath))
        return false;
    }

    checkedNodes.insert(curNode);
    curPath.erase(curNode);
    return true;
  }

  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    nodes.clear();
    checkedNodes.clear();
    for (auto &p : prerequisites) {
      nodes[p[1]].insert(p[0]);
    }

    std::unordered_set<int> curPath;
    for (auto &kv : nodes) {
      if (!dfs(kv.first, curPath))
        return false;
    }
    return true;
  }
};

// --- 性能测试 ---
std::vector<std::vector<int>> generateLargeDAG(int numCourses,
                                               int numPrerequisites) {
  std::vector<std::vector<int>> prerequisites;
  std::random_device rd;
  std::mt19937 gen(rd());

  for (int i = 0; i < numPrerequisites; ++i) {
    int course_a = std::uniform_int_distribution<>(0, numCourses - 2)(gen);
    int course_b =
        std::uniform_int_distribution<>(course_a + 1, numCourses - 1)(gen);
    prerequisites.push_back({course_b, course_a});
  }
  return prerequisites;
}

template <typename Func> long long measureTime(Func &&func) {
  auto start = std::chrono::high_resolution_clock::now();
  func();
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end - start)
      .count();
}

int main() {
  const int numCourses = 2000;
  const int numPrerequisites = 8000;
  const int iterations = 10;

  auto prerequisites = generateLargeDAG(numCourses, numPrerequisites);

  // 测试参数传递版本
  long long total_time_params = 0;
  for (int i = 0; i < iterations; ++i) {
    total_time_params += measureTime([&]() {
      SolutionParams s;
      s.canFinish(numCourses, prerequisites);
    });
  }
  std::cout << "参数传递版本平均耗时: " << total_time_params / iterations
            << " microseconds" << std::endl;

  // 测试成员变量版本
  long long total_time_member = 0;
  for (int i = 0; i < iterations; ++i) {
    total_time_member += measureTime([&]() {
      SolutionMember s;
      s.canFinish(numCourses, prerequisites);
    });
  }
  std::cout << "成员变量版本平均耗时: " << total_time_member / iterations
            << " microseconds" << std::endl;

  return 0;
}
