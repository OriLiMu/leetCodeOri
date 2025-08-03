#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Node {
public:
  int val;
  Node *next;
  Node *random;
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;
    unordered_map<Node *, Node *> map;
    Node *cur = head;
    for (; cur; cur = cur->next) {
      map[cur] = new Node(cur->val);
    }

    cur = head;
    for (; cur; cur = cur->next) {
      map[cur]->next = map[cur->next];
      map[cur]->random = map[cur->random];
    }

    return map[head];
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
