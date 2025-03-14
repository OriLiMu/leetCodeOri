#include <iostream>
#include <vector>

using namespace std;

// 递归函数，用于生成所有组合
void generateCombinations(const vector<int> &nums, int m, int start,
                          vector<int> &current, vector<vector<int>> &result) {
  // 如果当前组合的大小等于 m，将其添加到结果中
  if (current.size() == m) {
    cout << "inserted" << endl;
    result.push_back(current);
    return;
  }

  // 遍历数组，生成组合
  for (int i = start; i < nums.size(); ++i) {
    current.push_back(nums[i]); // 选择当前数字
    cout << "push back" << nums[i] << endl;
    generateCombinations(nums, m, i + 1, current, result); // 递归处理下一个数字
    cout << "pop" << endl;
    current.pop_back(); // 回溯，移除当前数字
  }
}

// 主函数
vector<vector<int>> combinations(const vector<int> &nums, int m) {
  vector<vector<int>> result;                        // 存储所有组合
  vector<int> current;                               // 存储当前组合
  generateCombinations(nums, m, 0, current, result); // 生成组合
  return result;
}

// 测试代码
int main() {
  vector<int> nums = {1, 2, 3, 4}; // 输入数组
  int m = 4;                       // 组合大小

  vector<vector<int>> result = combinations(nums, m);

  // 输出所有组合
  for (const auto &comb : result) {
    for (int num : comb) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
