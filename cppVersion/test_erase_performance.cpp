#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// 版本1：使用 erase
class SolutionWithErase {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> u;
        for (auto &n : nums) {
            if (u.contains(n))
                continue;
            bool le = u.contains(n + 1);
            bool re = u.contains(n - 1);
            if (le && re) {
                int rre = u[n + 1];
                int rle = u[n - 1];
                u[rre] = rle;
                u[rle] = rre;
                if (n - 1 != rle)
                    u.erase(n - 1);
                if (n + 1 != rre)
                    u.erase(n + 1);
            } else if (le) {
                u[n] = u[n + 1];
                u[u[n + 1]] = n;
                if (n + 1 != u[n])
                    u.erase(n + 1);
            } else if (re) {
                u[n] = u[n - 1];
                u[u[n - 1]] = n;
                if (n - 1 != u[n])
                    u.erase(n - 1);
            } else
                u[n] = n;
        }

        int maxlen = 0;
        for (auto &kv : u) {
            maxlen = max(abs(kv.second - kv.first) + 1, maxlen);
        }
        return maxlen;
    }
};

// 版本2：不使用 erase
class SolutionWithoutErase {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> u;
        for (auto &n : nums) {
            if (u.contains(n))
                continue;
            bool le = u.contains(n + 1);
            bool re = u.contains(n - 1);
            if (le && re) {
                int rre = u[n + 1];
                int rle = u[n - 1];
                u[rre] = rle;
                u[rle] = rre;
                // 不删除中间节点
            } else if (le) {
                u[n] = u[n + 1];
                u[u[n + 1]] = n;
                // 不删除中间节点
            } else if (re) {
                u[n] = u[n - 1];
                u[u[n - 1]] = n;
                // 不删除中间节点
            } else
                u[n] = n;
        }

        int maxlen = 0;
        for (auto &kv : u) {
            maxlen = max(abs(kv.second - kv.first) + 1, maxlen);
        }
        return maxlen;
    }
};

// 生成测试数据
vector<int> generateTestData(int size, int range) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-range, range);
    
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        nums[i] = dis(gen);
    }
    return nums;
}

// 性能测试函数
void runPerformanceTest(const string& name, auto& solution, vector<int>& nums, int iterations) {
    auto start = high_resolution_clock::now();
    
    for (int i = 0; i < iterations; i++) {
        volatile int result = solution.longestConsecutive(nums);
        (void)result; // 防止被优化掉
    }
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    
    cout << name << ": " << duration << " 微秒 (" << iterations << " 次)" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "最长连续序列性能测试" << endl;
    cout << "========================================" << endl << endl;

    // 测试用例1：小数据集
    cout << "--- 测试1: 小数据集 (1000个元素) ---" << endl;
    vector<int> test1 = generateTestData(1000, 10000);
    SolutionWithErase s1_erase;
    SolutionWithoutErase s1_noerase;
    
    runPerformanceTest("带 erase", s1_erase, test1, 100);
    runPerformanceTest("不带 erase", s1_noerase, test1, 100);
    cout << endl;

    // 测试用例2：中等数据集
    cout << "--- 测试2: 中等数据集 (10000个元素) ---" << endl;
    vector<int> test2 = generateTestData(10000, 100000);
    SolutionWithErase s2_erase;
    SolutionWithoutErase s2_noerase;
    
    runPerformanceTest("带 erase", s2_erase, test2, 10);
    runPerformanceTest("不带 erase", s2_noerase, test2, 10);
    cout << endl;

    // 测试用例3：大数据集
    cout << "--- 测试3: 大数据集 (100000个元素) ---" << endl;
    vector<int> test3 = generateTestData(100000, 1000000);
    SolutionWithErase s3_erase;
    SolutionWithoutErase s3_noerase;
    
    runPerformanceTest("带 erase", s3_erase, test3, 1);
    runPerformanceTest("不带 erase", s3_noerase, test3, 1);
    cout << endl;

    // 测试用例4：连续序列（极端情况）
    cout << "--- 测试4: 连续序列 (10000个连续元素) ---" << endl;
    vector<int> test4;
    for (int i = 0; i < 10000; i++) {
        test4.push_back(i);
    }
    SolutionWithErase s4_erase;
    SolutionWithoutErase s4_noerase;
    
    runPerformanceTest("带 erase", s4_erase, test4, 10);
    runPerformanceTest("不带 erase", s4_noerase, test4, 10);
    cout << endl;

    // 测试用例5：全部不连续（极端情况）
    cout << "--- 测试5: 全部不连续 (10000个随机间隔) ---" << endl;
    vector<int> test5;
    for (int i = 0; i < 10000; i++) {
        test5.push_back(i * 1000);
    }
    SolutionWithErase s5_erase;
    SolutionWithoutErase s5_noerase;
    
    runPerformanceTest("带 erase", s5_erase, test5, 10);
    runPerformanceTest("不带 erase", s5_noerase, test5, 10);
    cout << endl;

    cout << "========================================" << endl;
    cout << "测试完成" << endl;
    cout << "========================================" << endl;

    return 0;
}
