#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
struct Node {
  char c;
  bool isEnd;
  unordered_map<char, Node *> nextNodes;
  Node(char c = '\0', unordered_map<char, Node *> nextNodes = {},
       bool isEnd = false)
      : c(c), nextNodes(nextNodes) {};
};
class Solution {

public:
  void deleteNode(Node *node) {
    for (auto it = node->nextNodes.begin(); it != node->nextNodes.end();) {
      cout << "delete nextNodes " << it->first << endl;
      deleteNode(it->second);
      it = node->nextNodes.erase(it);
      cout << "this turn done" << endl;
    }

    delete node;
  }
  int similarPairs(vector<string> &words) {
    for (auto &str : words) {
      sort(str.begin(), str.end());
    }
    sort(words.begin(), words.end());
    Node *head = new Node('A', {}, false);
    Node *curNode = head;
    int result = 0;

    for (auto &word : words) {
      for (int i = 0; i < word.size(); i++) {
        if (i == word.size() - 1) {
          curNode->isEnd = true;
        }
        char c = word[i];
        if (curNode->c == c ||
            curNode->nextNodes.find(c) != curNode->nextNodes.end()) {
          if (curNode->isEnd && i == word.size() - 1) {
            result++;
            curNode = head;
            break;
          }
          if (curNode->c != c) {
            curNode = curNode->nextNodes[c];
          }
        } else {
          Node *tmp = new Node(c, {}, false);
          curNode->nextNodes.insert({c, tmp});
          curNode = curNode->nextNodes[c];
          if (i == word.size() - 1) {
            curNode->isEnd = true;
            curNode = head;
          }
        }
      }
    }

    deleteNode(head);
    return result;
  }
};
int main() {
  Solution s;
  vector<string> v = {"aba", "aabb", "abcd", "bac", "aabc"};
  int r = s.similarPairs(v);
  cout << r << endl;
}
