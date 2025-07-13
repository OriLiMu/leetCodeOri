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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode preHead = {0, head};
    ListNode *rhead = head;
    ListNode *left = &preHead, *right = head;
    int t = 0;
    if (n == 1 && head->next == nullptr) {
      return nullptr;
    }

    while (t++ < n - 1 && right && right->next) {
      right = right->next;
    }
    while (right->next) {
      left = left->next;
      right = right->next;
    }
    left->next = left->next->next;
    if (left == &preHead) {
      rhead = left->next;
    }
    return rhead;
  }
};

int main() {
  Solution s;
  ListNode *head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode *res = s.removeNthFromEnd(head, 2);
  while (res) {
    cout << res->val << endl;
    res = res->next;
  }
  return 0;
}

