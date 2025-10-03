#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class OriginalSolution {
public:
    bool dfs(int curNode, unordered_set<int> &curPath,
             unordered_set<int> &checkedNodes,
             unordered_map<int, unordered_set<int>> &nodes) {
        if (checkedNodes.find(curNode) != checkedNodes.end())
            return true;
        else if (find(curPath.begin(), curPath.end(), curNode) != curPath.end())
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

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, unordered_set<int>> nodes;
        for (auto p : prerequisites) {
            int key = p[1];
            int value = p[0];
            nodes[key].insert(value);
        }

        unordered_set<int> visitedNodesThisTurn;
        unordered_set<int> checkedNodes;
        for (auto &kv : nodes) {
            visitedNodesThisTurn.clear();
            if (!dfs(kv.first, visitedNodesThisTurn, checkedNodes, nodes))
                return false;
        }

        return true;
    }
};

class OptimizedSolution {
public:
    bool dfs(int curNode, vector<bool> &curPath,
             vector<bool> &checkedNodes,
             vector<vector<int>> &nodes) {
        if (checkedNodes[curNode])
            return true;
        else if (curPath[curNode])
            return false;

        curPath[curNode] = true;
        for (auto &child : nodes[curNode]) {
            if (!dfs(child, curPath, checkedNodes, nodes))
                return false;
        }

        checkedNodes[curNode] = true;
        curPath[curNode] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> nodes(numCourses);
        for (auto p : prerequisites) {
            int key = p[1];
            int value = p[0];
            nodes[key].push_back(value);
        }

        vector<bool> curPath(numCourses, false);
        vector<bool> checkedNodes(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            fill(curPath.begin(), curPath.end(), false);
            if (!dfs(i, curPath, checkedNodes, nodes))
                return false;
        }

        return true;
    }
};

class TestGenerator {
public:
    static vector<vector<int>> generateLinearDependencies(int numCourses) {
        vector<vector<int>> prerequisites;
        for (int i = 1; i < numCourses; i++) {
            prerequisites.push_back({i, i-1});
        }
        return prerequisites;
    }

    static vector<vector<int>> generateRandomDependencies(int numCourses, int density = 3) {
        vector<vector<int>> prerequisites;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> courseDist(0, numCourses - 1);

        for (int i = 0; i < numCourses * density; i++) {
            int course = courseDist(gen);
            int prereq = courseDist(gen);
            if (course != prereq) {
                prerequisites.push_back({course, prereq});
            }
        }
        return prerequisites;
    }

    static vector<vector<int>> generateWithCycle(int numCourses) {
        vector<vector<int>> prerequisites = generateLinearDependencies(numCourses);
        prerequisites.push_back({0, numCourses - 1});
        return prerequisites;
    }
};

class PerformanceTester {
public:
    template<typename Func>
    static long long measureTime(Func func) {
        auto start = high_resolution_clock::now();
        func();
        auto end = high_resolution_clock::now();
        return duration_cast<microseconds>(end - start).count();
    }

    static void runTest(int numCourses, vector<vector<int>> &prerequisites, const string& testName) {
        OriginalSolution original;
        OptimizedSolution optimized;

        cout << "\n=== " << testName << " (numCourses: " << numCourses << ") ===" << endl;
        cout << "Prerequisites count: " << prerequisites.size() << endl;

        bool originalResult, optimizedResult;
        long long originalTime, optimizedTime;

        originalTime = measureTime([&]() {
            originalResult = original.canFinish(numCourses, prerequisites);
        });

        optimizedTime = measureTime([&]() {
            optimizedResult = optimized.canFinish(numCourses, prerequisites);
        });

        cout << "Original result: " << (originalResult ? "true" : "false") << endl;
        cout << "Optimized result: " << (optimizedResult ? "true" : "false") << endl;
        cout << "Original time: " << originalTime << " μs" << endl;
        cout << "Optimized time: " << optimizedTime << " μs" << endl;

        if (originalTime > 0) {
            double speedup = (double)originalTime / optimizedTime;
            cout << "Speedup: " << fixed << setprecision(2) << speedup << "x" << endl;
        }

        cout << "Correctness: " << (originalResult == optimizedResult ? "✓ PASS" : "✗ FAIL") << endl;
    }
};

int main() {
    cout << "=== Performance Test: unordered_set vs vector ===" << endl;

    vector<int> testSizes = {100, 500, 1000, 2000, 5000};

    for (int size : testSizes) {
        auto linearDeps = TestGenerator::generateLinearDependencies(size);
        PerformanceTester::runTest(size, linearDeps, "Linear Dependencies (No Cycle)");

        auto randomDeps = TestGenerator::generateRandomDependencies(size, 2);
        PerformanceTester::runTest(size, randomDeps, "Random Dependencies");

        if (size <= 1000) {
            auto cycleDeps = TestGenerator::generateWithCycle(size);
            PerformanceTester::runTest(size, cycleDeps, "Linear Dependencies with Cycle");
        }
    }

    cout << "\n=== Performance Test Summary ===" << endl;
    cout << "Test completed. Check results above for detailed performance comparison." << endl;

    return 0;
}