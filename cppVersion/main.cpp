#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <ranges>
#include <string>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Trie {
public:
  struct TreeNode {
    char c;
    bool isEnd; // 这里需要一个end标记, size被resize无法判断是不是还有child
    vector<TreeNode *> children;
    TreeNode(char cc) : c(cc) {
      children.resize(26);
      isEnd = false; // 这里的值怎么设置
    }
  };
  TreeNode *dummy;
  Trie() { dummy = new TreeNode('\0'); } // 这里的初始化值需要注意
  // 其中的一个索引表是不需要的

  void insert(string word) {
    if (!word.size())
      return;
    // 这里还有一个最大的错误就是指针虚表的问题.
    // 如果你想修改一个指针所指向的内容你需要找到他爹
    TreeNode *parent = dummy;
    for (int i = 0; i < word.size(); ++i) {
      int cIdx = static_cast<int>(word[i] - 'a');
      if (!parent->children[cIdx])
        parent->children[cIdx] = new TreeNode(word[i]);
      parent = parent->children[cIdx];
    }
    parent->isEnd = true;
  }

  bool search(string word) {
    TreeNode *p = dummy;
    for (int i = 0; i < word.size(); ++i) {
      int idx = static_cast<int>(word[i] - 'a');
      if (!p->children[idx])
        return false;
      p = p->children[idx];
    }

    return p->isEnd;
  }

  bool startsWith(string prefix) {
    vector<TreeNode *> children = dummy->children;
    for (int i = 0; i < prefix.size(); ++i) {
      int idx = static_cast<int>(prefix[i] - 'a');
      if (!children[idx])
        return false;
      children = children[idx]->children;
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
  Trie s;
  s.insert("apple");
  s.search("apple");
  cout << "test" << endl;
}
