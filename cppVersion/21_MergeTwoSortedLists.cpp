#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 根据给定的整型 vector 构建一条单链表。
 * 返回链表的头结点指针。若 vector 为空，返回 nullptr。
 * 例：buildChainTable({1, 2, 3}) -> 1 -> 2 -> 3 -> nullptr
 */
ListNode *buildChainTable(const std::vector<int> &values) {
  if (values.empty()) {
    return nullptr;
  }

  // 创建头结点
  ListNode *head = new ListNode(values[0]);
  ListNode *cur = head;

  // 依次创建并连接后续结点
  for (size_t i = 1; i < values.size(); ++i) {
    cur->next = new ListNode(values[i]);
    cur = cur->next;
  }

  return head;
}

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *p1 = list1, *p2 = list2;
    ListNode dummy(0);
    ListNode *p3 = &dummy;
    while (p1 && p2) {
      if (p1->val > p2->val) {
        p3->next = p2;
        p2 = p2->next;
      } else {
        p3->next = p1;
        p1 = p1->next;
      }
      p3 = p3->next;
    }
    if (p1) {
      p3->next = p1;
    }
    if (p2) {
      p3->next = p2;
    }

    return dummy.next;
  }
};
int main() {
  Solution s;
  vector<int> v1 = {1, 2, 4};
  vector<int> v2 = {1, 3, 4};
  ListNode *p1 = buildChainTable(v1);
  ListNode *p2 = buildChainTable(v2);
  ListNode *p3 = s.mergeTwoLists(p1, p2);
  while (p3) {
    cout << p3->val << ", ";
    p3 = p3->next;
  }
}
