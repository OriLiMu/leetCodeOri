#include <array>
#include <iostream>
#include <string>

using namespace std;

// 代码效率的提升居然来源于array
class Trie {
public:
  struct TreeNode {
    // char c;     // 这个没必要
    bool isEnd; // 这里需要一个end标记, size被resize无法判断是不是还有child
    array<TreeNode *, 26> children;
    TreeNode() : isEnd(false) { children.fill(nullptr); }
  };
  TreeNode *dummy;
  Trie() { dummy = new TreeNode(); } // 这里的初始化值需要注意
  // 其中的一个索引表是不需要的

  void insert(string word) {
    // 这里还有一个最大的错误就是指针虚表的问题.
    // 如果你想修改一个指针所指向的内容你需要找到他爹
    TreeNode *parent = dummy;
    for (int i = 0; i < word.size(); ++i) {
      if (!parent->children[word[i] - 'a'])
        parent->children[word[i] - 'a'] = new TreeNode();
      parent = parent->children[word[i] - 'a'];
    }
    parent->isEnd = true;
  }

  bool search(string word) {
    TreeNode *p = dummy;
    for (int i = 0; i < word.size(); ++i) {
      if (!p->children[word[i] - 'a'])
        return false;
      p = p->children[word[i] - 'a'];
    }

    return p->isEnd;
  }

  bool startsWith(string prefix) {
    TreeNode *parent = dummy; // 这里有一个vector拷贝, 消耗性能
    for (int i = 0; i < prefix.size(); ++i) {
      if (!parent->children[prefix[i] - 'a'])
        return false;
      parent = parent->children[prefix[i] - 'a'];
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
