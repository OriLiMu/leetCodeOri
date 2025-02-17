#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main() {
  vector<string> strings = {"ab", "cd", "ef"};
  vector<string> permutations = generateAllPermutations(strings);

  cout << "所有排列组合：" << endl;
  for (const string &perm : permutations) {
    cout << perm << endl;
  }

  return 0;
}
