#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <strings.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Trie {
public:
  vector<vector<int>> trie;
  Trie() {}

  void insert(string word) {
    for (int i = 0; i < word.size(); ++i) {
      int idx = static_cast<int>(word[i] - 'a');
      if (i + 1 > trie.size())
        trie.push_back(vector<int>(26));
      trie[i][idx] = 1;
    }
  }

  bool search(string word) {
    for (int i = 0; i < word.size(); ++i) {
      int idx = static_cast<int>(word[i] - 'a');
      if (i + 1 > trie.size() || trie[i][idx] == 0)
        return false;
    }

    return true;
  }

  bool startsWith(string prefix) { return search(prefix); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
  Solution s;
  cout << "hello" << endl;
}
