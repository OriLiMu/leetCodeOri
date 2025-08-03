#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <new>
#include <sys/types.h>
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
  vector<ListNode *> reverseKNode(ListNode *head, int K) {
    if (head == nullptr)
      return {nullptr, nullptr, nullptr};
    ListNode *mtail = head;
    ListNode *mhead = nullptr;
    ListNode *next_head = nullptr;

    ListNode *cur = head;
    ListNode *prev = nullptr;
    ListNode *next = cur->next;
    int count = 0;
    while (count < K) {
      if (cur == nullptr) {
        return {nullptr, nullptr, nullptr};
      }
      prev = cur;
      cur = cur->next;
      count++;
    }

    cur = head;
    prev = nullptr;
    count = 0;
    while (cur && count < K) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      count++;
    }
    mhead = prev;
    next_head = next;
    mtail->next = nullptr;

    return {mhead, mtail, next_head};
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    vector<ListNode *> lnResult = {nullptr, nullptr, nullptr};
    ListNode *curHead = nullptr;
    ListNode *tailNode = nullptr;
    ListNode *nextHead = head;
    ListNode *resultHead = head;
    bool isHeadSet = false;
    while (true) {
      if (nextHead == nullptr)
        break;
      lnResult = reverseKNode(nextHead, k);
      if (all_of(lnResult.begin(), lnResult.end(),
                 [](ListNode *node) { return node == nullptr; })) {
        if (tailNode) {
          tailNode->next = nextHead;
        }
        break;
      }

      if (tailNode && lnResult[0]) {
        tailNode->next = lnResult[0];
      }
      curHead = lnResult[0];
      tailNode = lnResult[1];
      nextHead = lnResult[2];
      if (!isHeadSet) {
        resultHead = curHead;
        isHeadSet = true;
      }
    }

    return resultHead;
  }
};

int main() {
  Solution s;
  ListNode *head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode *result = s.reverseKGroup(head, 1);
  while (result) {
    cout << result->val << " ";
    result = result->next;
  }
}

