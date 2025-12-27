#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace chrono;

// 第一个算法：递归解法
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0)
        {
            int left = findKthNumber(nums1, 0, nums2, 0, total / 2);
            int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        }
        else
        {
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }

    int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        if (nums1.size() - i > nums2.size() - j) return findKthNumber(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2;
        if (nums1[si - 1] > nums2[sj - 1])
        {
            return findKthNumber(nums1, i, nums2, j + k / 2, k - k / 2);
        }
        else
        {
            return findKthNumber(nums1, si, nums2, j, k - (si - i));
        }
    }
};

// 第二个算法：迭代二分解法
class Solution2 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int rl = (l1 + l2) / 2;
        int l3 = rl;
        int s1 = 0, s2 = 0;
        bool isOdd = (l1 + l2) % 2 == 0 ? false : true;
        while (rl > 0) {
            if ((nums1.size() - s1) < (nums2.size() - s2)) {
                swap(nums1, nums2);
                swap(s1, s2);
            }

            if (s2 == nums2.size()) {
                s1 += rl;
                if (isOdd)
                    return nums1[s1];
                else
                    return (nums1[s1] + nums1[s1 - 1]) / 2.0;
            }

            int sp1 = s1 + rl - rl / 2 - 1,
                sp2 = s2 + max(rl / 2 - 1, 0);

            if (nums2.size() - s2 < rl / 2) {
                sp1 = s1 + rl - (nums2.size() - s2) - 1;
                sp2 = nums2.size() - 1;
                if (nums2[sp2] > nums1[sp1]) {
                    s1 = sp1 + 1;
                    rl = nums2.size() - s2;
                } else {
                    rl -= nums2.size() - s2;
                    s2 = sp2 + 1;
                }
            } else {
                if (nums1[sp1] > nums2[sp2]) {
                    s2 = sp2 + 1;
                    rl = rl - max(1, rl / 2);
                } else {
                    s1 = sp1 + 1;
                    rl = rl / 2;
                }
            }
        }

        if (isOdd) {
            if (s1 == nums1.size())
                return nums2[s2];
            if (s2 == nums2.size())
                return nums1[s1];
            return nums1[s1] < nums2[s2] ? nums1[s1] : nums2[s2];
        } else {
            if (s1 == nums1.size()) {
                if (s2 == 0)
                    return (nums1[s1 - 1] + nums2[s2]) / 2.0;
                return (max(nums1[s1 - 1], nums2[s2 - 1]) + nums2[s2]) / 2.0;
            } else if (s2 == nums2.size()) {
                if (s1 == 0)
                    return (nums2[s2 - 1] + nums1[s1]) / 2.0;
                return (max(nums1[s1 - 1], nums2[s2 - 1]) + nums1[s1]) / 2.0;
            }

            if (s1 == 0 && s2 == 0)
                return (nums1[s1] + nums2[s2]) / 2.0;
            else if (s1 == 0 && s2 != 0)
                return (min(nums1[s1], nums2[s2]) + nums2[s2 - 1]) / 2.0;
            else if (s1 != 0 && s2 == 0)
                return (min(nums1[s1], nums2[s2]) + nums1[s1 - 1]) / 2.0;
            return (min(nums1[s1], nums2[s2]) + max(nums1[s1 - 1], nums2[s2 - 1])) /
                   2.0;
        }
    }
};

// 生成有序随机数组
vector<int> generateSortedArray(int size, int minVal, int maxVal) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minVal, maxVal);

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    sort(arr.begin(), arr.end());
    return arr;
}

// 测试单个算法的性能
template<typename T>
double testAlgorithm(T& solution, const vector<int>& nums1, const vector<int>& nums2, int iterations = 1000) {
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++) {
        // 创建副本以避免修改原数组
        vector<int> n1 = nums1;
        vector<int> n2 = nums2;
        volatile double result = solution.findMedianSortedArrays(n1, n2);
        (void)result; // 防止优化
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    return duration.count() / (double)iterations;
}

// 验证两个算法结果是否一致
bool verifyCorrectness(Solution1& sol1, Solution2& sol2, const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> n1_1 = nums1, n2_1 = nums2;
    vector<int> n1_2 = nums1, n2_2 = nums2;

    double result1 = sol1.findMedianSortedArrays(n1_1, n2_1);
    double result2 = sol2.findMedianSortedArrays(n1_2, n2_2);

    if (abs(result1 - result2) > 1e-9) {
        cout << "  警告: 结果不一致!" << endl;
        cout << "  Solution1: " << result1 << ", Solution2: " << result2 << endl;
        return false;
    }
    return true;
}

void runTest(int size1, int size2, int iterations) {
    Solution1 sol1;
    Solution2 sol2;

    cout << "\n测试用例: nums1大小=" << size1 << ", nums2大小=" << size2 << endl;

    vector<int> nums1 = generateSortedArray(size1, 0, 10000);
    vector<int> nums2 = generateSortedArray(size2, 0, 10000);

    // 验证正确性
    if (!verifyCorrectness(sol1, sol2, nums1, nums2)) {
        cout << "  跳过性能测试（结果不一致）" << endl;
        return;
    }

    // 测试性能
    double time1 = testAlgorithm(sol1, nums1, nums2, iterations);
    double time2 = testAlgorithm(sol2, nums1, nums2, iterations);

    cout << fixed << setprecision(3);
    cout << "  Solution1 (递归): " << setw(10) << time1 << " 微秒/次" << endl;
    cout << "  Solution2 (迭代): " << setw(10) << time2 << " 微秒/次" << endl;

    if (time1 < time2) {
        cout << "  Solution1 快 " << (time2 / time1) << " 倍" << endl;
    } else if (time2 < time1) {
        cout << "  Solution2 快 " << (time1 / time2) << " 倍" << endl;
    } else {
        cout << "  性能相当" << endl;
    }
}

int main() {
    cout << "========================================" << endl;
    cout << "两个中位数查找算法性能对比测试" << endl;
    cout << "========================================" << endl;

    // 测试不同规模的用例
    vector<pair<int, int>> testCases = {
        {10, 10},         // 小数组
        {100, 100},       // 中小数组
        {1000, 1000},     // 中等数组
        {10000, 10000},   // 大数组
        {100000, 100000}, // 超大数组
        {0, 100},         // 一个空数组
        {10, 10000},      // 长度差异大
        {10000, 10},      // 长度差异大（反转）
    };

    for (const auto& testCase : testCases) {
        int iterations;
        if (testCase.first <= 1000 && testCase.second <= 1000) {
            iterations = 10000;
        } else if (testCase.first <= 10000 && testCase.second <= 10000) {
            iterations = 1000;
        } else {
            iterations = 100;
        }
        runTest(testCase.first, testCase.second, iterations);
    }

    cout << "\n========================================" << endl;
    cout << "测试完成" << endl;
    cout << "========================================" << endl;

    return 0;
}
