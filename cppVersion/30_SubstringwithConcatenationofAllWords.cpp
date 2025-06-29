#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateAllPermutations(const vector<string> &strings) {
    vector<string> result;
    vector<string> temp = strings;
    // 排序以便生成所有排列
    sort(temp.begin(), temp.end());
    do {
      string combo;
      for (const string &s : temp) {
        combo += s;
      }
      result.push_back(combo);
    } while (next_permutation(temp.begin(), temp.end()));
    return result;
  }

  vector<int> find_substring_positions(const std::string &str,
                                       const std::string &substr) {
    vector<int> positions;
    size_t pos = str.find(substr); // 查找第一个匹配的位置

    // 循环查找所有匹配的位置
    while (pos != std::string::npos) {
      positions.push_back(pos);        // 存储匹配的位置
      pos = str.find(substr, pos + 1); // 从下一个位置继续查找
    }

    return positions;
  }

  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> positions = find_substring_positions(s, words[0]);
    vector<string> AllPermutaions = generateAllPermutations(words);
    int permuationLen = words.size() * words[0].size();
    vector<int> result;
    for (string permuation : AllPermutaions) {
      for (int i = 0; i < positions.size(); i++) {
        int wordPosInPermutation = permuation.find(words[0]);
        int left = positions[i] - wordPosInPermutation;
        int right = positions[i] + words[0].size() - wordPosInPermutation - 1;
        if (left >= 0 && right < s.size()) {
          if (s.substr(left, permuationLen) == permuation) {
            result.push_back(left);
          }
        } else {
          continue;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<string> words = {"a"};
  vector<int> result = s.findSubstring("a", words);
  for (int i : result) {
    cout << i << " ";
  }
  return 0;
}

