#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    ListNode *cur = head;
    ListNode *last = nullptr;
    ListNode *next = nullptr;
    while (cur) {
      next = cur->next;
      cur->next = last;
      last = cur;
      cur = next;
    }

    return last;
  }
};
int main() { Solution s; }
