#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/**
 * 广度优先搜索 (BFS) 函数
 * @param graph 邻接表表示的图
 * @param start 开始遍历的节点
 * @return BFS 遍历顺序的节点序列
 */
vector<int> bfs(const vector<vector<int>>& graph, int start = 0) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> result;
    queue<int> q;

    // 从起始节点开始
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        // 访问所有邻接节点
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}

/**
 * 打印遍历结果
 */
void printResult(const vector<int>& result, const string& testName) {
    cout << "========== " << testName << " ==========" << endl;
    cout << "BFS 遍历顺序: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    cout << "遍历节点数量: " << result.size() << endl;
    cout << endl;
}

/**
 * 打印图结构
 */
void printGraph(const vector<vector<int>>& graph, const string& testName) {
    cout << "---------- " << testName << " 图结构 ----------" << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << "节点 " << i << " -> ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "     BFS (广度优先搜索) 测试程序       " << endl;
    cout << "========================================" << endl << endl;

    // ==================== 测试用例 1: 简单线性图 ====================
    // 结构: 0 -> 1 -> 2 -> 3 -> 4
    {
        string testName = "测试用例 1: 简单线性图";
        cout << "结构: 0 -> 1 -> 2 -> 3 -> 4" << endl;

        vector<vector<int>> graph(5);
        graph[0] = {1};
        graph[1] = {2};
        graph[2] = {3};
        graph[3] = {4};
        graph[4] = {};

        printGraph(graph, testName);
        vector<int> result = bfs(graph, 0);
        printResult(result, testName);
    }

    // ==================== 测试用例 2: 树形结构 ====================
    // 结构:     0
    //         /   \
    //        1     2
    //       / \   / \
    //      3   4 5   6
    {
        string testName = "测试用例 2: 树形结构";
        cout << "结构:     0" << endl;
        cout << "         /   \\" << endl;
        cout << "        1     2" << endl;
        cout << "       / \\   / \\" << endl;
        cout << "      3   4 5   6" << endl;

        vector<vector<int>> graph(7);
        graph[0] = {1, 2};
        graph[1] = {3, 4};
        graph[2] = {5, 6};
        graph[3] = {};
        graph[4] = {};
        graph[5] = {};
        graph[6] = {};

        printGraph(graph, testName);
        vector<int> result = bfs(graph, 0);
        printResult(result, testName);
    }

    // ==================== 测试用例 3: 环形图 ====================
    // 结构: 0 <-> 1 <-> 2 <-> 3
    //        ^_______________|
    {
        string testName = "测试用例 3: 环形图";
        cout << "结构: 0 <-> 1 <-> 2 <-> 3" << endl;
        cout << "        ^_______________|" << endl;

        vector<vector<int>> graph(4);
        graph[0] = {1, 3};
        graph[1] = {0, 2};
        graph[2] = {1, 3};
        graph[3] = {2, 0};

        printGraph(graph, testName);
        vector<int> result = bfs(graph, 0);
        printResult(result, testName);
    }

    // ==================== 测试用例 4: 不连通图 ====================
    // 结构: 两个独立的连通分量 [0,1] 和 [2,3,4]
    {
        string testName = "测试用例 4: 不连通图";
        cout << "结构: 两个独立的连通分量 [0,1] 和 [2,3,4]" << endl;

        vector<vector<int>> graph(5);
        graph[0] = {1};
        graph[1] = {0};
        graph[2] = {3};
        graph[3] = {2, 4};
        graph[4] = {3};

        printGraph(graph, testName);
        cout << "注意: 从节点 0 开始，只能访问到连通分量 [0,1]" << endl;
        vector<int> result = bfs(graph, 0);
        printResult(result, testName);
    }

    // ==================== 测试用例 5: 复杂图 ====================
    // 多层结构，节点之间有复杂连接
    {
        string testName = "测试用例 5: 复杂图";
        cout << "结构: 多层复杂连接图" << endl;

        vector<vector<int>> graph(8);
        graph[0] = {1, 2, 3};
        graph[1] = {0, 4, 5};
        graph[2] = {0, 5};
        graph[3] = {0, 6};
        graph[4] = {1, 7};
        graph[5] = {1, 2, 7};
        graph[6] = {3, 7};
        graph[7] = {4, 5, 6};

        printGraph(graph, testName);
        vector<int> result = bfs(graph, 0);
        printResult(result, testName);
    }

    // ==================== 测试用例 6: 单节点 ====================
    // 结构: 只有一个节点 0
    {
        string testName = "测试用例 6: 单节点";
        cout << "结构: 只有一个节点 0" << endl;

        vector<vector<int>> graph(1);
        graph[0] = {};

        printGraph(graph, testName);
        vector<int> result = bfs(graph, 0);
        printResult(result, testName);
    }

    // ==================== 测试用例 7: 星形图 ====================
    // 结构:     1
    //         / | \
    //        2  0  3
    //           |
    //           4
    {
        string testName = "测试用例 7: 星形图";
        cout << "结构: 中心节点 0，连接所有其他节点" << endl;

        vector<vector<int>> graph(5);
        graph[0] = {1, 2, 3, 4};
        graph[1] = {0};
        graph[2] = {0};
        graph[3] = {0};
        graph[4] = {0};

        printGraph(graph, testName);
        vector<int> result = bfs(graph, 0);
        printResult(result, testName);
    }

    cout << "========================================" << endl;
    cout << "        所有测试用例运行完成           " << endl;
    cout << "========================================" << endl;

    return 0;
}
