#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
struct Node {
  char c;
  unordered_map<char, Node *> nextNodes;
  Node(char c = '\0', unordered_map<char, Node *> nextNodes = {})
      : c(c), nextNodes(nextNodes) {};
};
class Solution {

public:
  void deleteNode(Node *node) {
    if (node->nextNodes.empty()) {
      delete node;
    } else {
      for (auto it = node->nextNodes.begin(); it != node->nextNodes.end();
           ++it) {
        deleteNode(it->second);
        node->nextNodes.erase(it->first);
      }
    }
  }
  int similarPairs(vector<string> &words) {
    for (auto &str : words) {
      sort(str.begin(), str.end());
    }
    sort(words.begin(), words.end());
    Node head = {'A', {}};
    Node *curNode = &head;
    int result = 0;

    for (auto &word : words) {
      for (int i = 0; i < word.size(); i++) {
        char c = word[i];
        if (curNode->c == c ||
            curNode->nextNodes.find(c) != curNode->nextNodes.end()) {
          if (curNode->nextNodes.empty() && i == word.size() - 1) {
            result++;
            curNode = &head;
            break;
          }
          if (curNode->c != c) {
            curNode = curNode->nextNodes[c];
          }
        } else {
          Node *tmp = new Node(c, {});
          curNode->nextNodes.insert({c, tmp});
          curNode = curNode->nextNodes[c];
        }
      }
    }

    deleteNode(&head);
    return result;
  }
};
int main() {
  Solution s;
  vector<string> v = {"aba", "aabb", "abcd", "bac", "aabc"};
  int r = s.similarPairs(v);
  cout << r << endl;
}
