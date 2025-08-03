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
    Node *cur = head, dummy = Node(0), *curCopied = &dummy;
    unordered_map<Node *, int> nodeAddrToIndex;
    vector<Node *> copiedNodeAddr;
    int index = 0;
    for (; cur; cur = cur->next, curCopied = curCopied->next, index++) {
      curCopied->next = new Node(cur->val);
      nodeAddrToIndex[cur] = index;
      copiedNodeAddr.push_back(curCopied->next);
    }

    cur = head;
    curCopied = dummy.next;
    for (; cur; cur = cur->next, curCopied = curCopied->next) {
      if (!cur->random)
        curCopied->random = nullptr;
      else {
        curCopied->random = copiedNodeAddr[nodeAddrToIndex[cur->random]];
      }
    }

    return dummy.next;
  }
};
int main() {
  Solution s;
  cout << "hello" << endl;
}
