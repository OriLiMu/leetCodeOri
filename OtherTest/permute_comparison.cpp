#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::chrono;

class SolutionOriginal {
public:
    void func(vector<int> &allNums, int startIdx, vector<vector<int>> &result) {
        if (startIdx == allNums.size()) { // 原始方法：size()
            result.push_back(allNums);
            return;
        }

        for (int i = startIdx; i < allNums.size(); ++i) {
            swap(allNums[startIdx], allNums[i]);
            func(allNums, startIdx + 1, result);
            swap(allNums[startIdx], allNums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        func(nums, 0, result);
        return result;
    }
};

class SolutionOptimized {
public:
    void func(vector<int> &allNums, int startIdx, vector<vector<int>> &result) {
        if (startIdx == allNums.size() - 1) { // 优化方法：size()-1
            result.push_back(allNums);
            return;
        }

        for (int i = startIdx; i < allNums.size(); ++i) {
            swap(allNums[startIdx], allNums[i]);
            func(allNums, startIdx + 1, result);
            swap(allNums[startIdx], allNums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        func(nums, 0, result);
        return result;
    }
};

class SolutionWithBounds {
public:
    void func(vector<int> &allNums, int startIdx, vector<vector<int>> &result) {
        if (startIdx >= allNums.size()) { // 额外测试：>=
            result.push_back(allNums);
            return;
        }

        for (int i = startIdx; i < allNums.size(); ++i) {
            swap(allNums[startIdx], allNums[i]);
            func(allNums, startIdx + 1, result);
            swap(allNums[startIdx], allNums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        func(nums, 0, result);
        return result;
    }
};

// 性能测试函数
void performanceTest(int n, int iterations = 1000) {
    vector<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i);
    }

    SolutionOriginal sol1;
    SolutionOptimized sol2;
    SolutionWithBounds sol3;

    // 测试原始方法 size()
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        vector<int> numsCopy = nums;
        vector<vector<int>> result1 = sol1.permute(numsCopy);
    }
    auto end = high_resolution_clock::now();
    auto time1 = duration_cast<microseconds>(end - start).count();

    // 测试优化方法 size()-1
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        vector<int> numsCopy = nums;
        vector<vector<int>> result2 = sol2.permute(numsCopy);
    }
    end = high_resolution_clock::now();
    auto time2 = duration_cast<microseconds>(end - start).count();

    // 测试额外方法 >=
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        vector<int> numsCopy = nums;
        vector<vector<int>> result3 = sol3.permute(numsCopy);
    }
    end = high_resolution_clock::now();
    auto time3 = duration_cast<microseconds>(end - start).count();

    cout << "=== n = " << n << " ( permutations: " << (n <= 8 ? to_string(1) : "n!") << " ) ===" << endl;
    cout << "size() 方法:        " << time1 << " 微秒" << endl;
    cout << "size()-1 方法:      " << time2 << " 微秒";
    if (time2 < time1) {
        cout << "  (快 " << (double)(time1 - time2) / time1 * 100 << "%)";
    } else {
        cout << "  (慢 " << (double)(time2 - time1) / time1 * 100 << "%)";
    }
    cout << endl;

    cout << ">= 方法:            " << time3 << " 微秒" << endl;
    cout << "性能差异: size()-1 比 size() " << (time2 < time1 ? "快" : "慢") << endl;
    cout << endl;
}

// 递归次数分析
void analyzeRecursionDepth(int n) {
    cout << "=== 递归深度分析 (n=" << n << ") ===" << endl;

    vector<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i);
    }

    int recursionCalls1 = 0, recursionCalls2 = 0;

    // 为原始方法添加计数器
    function<void(vector<int>&, int)> func1 = [&](vector<int> &allNums, int startIdx) {
        recursionCalls1++;
        if (startIdx == allNums.size()) {
            return;
        }
        for (int i = startIdx; i < allNums.size(); ++i) {
            swap(allNums[startIdx], allNums[i]);
            func1(allNums, startIdx + 1);
            swap(allNums[startIdx], allNums[i]);
        }
    };

    // 为优化方法添加计数器
    function<void(vector<int>&, int)> func2 = [&](vector<int> &allNums, int startIdx) {
        recursionCalls2++;
        if (startIdx == allNums.size() - 1) {
            return;
        }
        for (int i = startIdx; i < allNums.size(); ++i) {
            swap(allNums[startIdx], allNums[i]);
            func2(allNums, startIdx + 1);
            swap(allNums[startIdx], allNums[i]);
        }
    };

    vector<int> numsCopy1 = nums;
    vector<int> numsCopy2 = nums;
    func1(numsCopy1, 0);
    func2(numsCopy2, 0);

    cout << "size() 方法递归调用次数: " << recursionCalls1 << endl;
    cout << "size()-1 方法递归调用次数: " << recursionCalls2 << endl;
    cout << "递归调用减少次数: " << (recursionCalls1 - recursionCalls2) << endl;
    cout << "减少百分比: " << (double)(recursionCalls1 - recursionCalls2) / recursionCalls1 * 100 << "%" << endl;
    cout << endl;
}

int main() {
    cout << "全排列算法性能比较：size() vs size()-1" << endl;
    cout << "=========================================" << endl;

    // 分析不同规模下的性能
    for (int n = 3; n <= 8; ++n) {
        analyzeRecursionDepth(n);

        // 根据n的大小调整测试次数
        int iterations = 1000;
        if (n >= 7) iterations = 100;
        if (n >= 8) iterations = 10;

        performanceTest(n, iterations);
    }

    cout << "=== 理论分析 ===" << endl;
    cout << "size() 方法递归深度: n+1" << endl;
    cout << "size()-1 方法递归深度: n" << endl;
    cout << "总排列数: n!" << endl;
    cout << "size() 方法总递归调用次数: (n+1) * n!" << endl;
    cout << "size()-1 方法总递归调用次数: n * n!" << endl;
    cout << "性能提升: 减少了 n! 次递归调用" << endl;

    return 0;
}