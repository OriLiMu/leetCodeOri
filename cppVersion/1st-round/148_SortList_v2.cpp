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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildChainTable(const std::vector<int> &nums) {
  if (nums.empty())
    return nullptr;

  ListNode *head = new ListNode(nums[0]);
  ListNode *cur = head;

  for (size_t i = 1; i < nums.size(); ++i) {
    cur->next = new ListNode(nums[i]);
    cur = cur->next;
  }
  return head;
}

class Solution {
public:
  vector<ListNode *> quick_sort(ListNode *h1, int len) {
    if (len <= 1)
      return {h1, h1};
    ListNode *h2 = h1, dummy(0, nullptr), *cur = nullptr, *tail = nullptr;
    int i = 0;
    while (i++ < len / 2 - 1) {
      h2 = h2->next;
    }
    ListNode *tmp = h2;
    h2 = h2->next, tmp->next = nullptr;
    vector<ListNode *> r1 = quick_sort(h1, len / 2);
    vector<ListNode *> r2 = quick_sort(h2, len - len / 2);
    h1 = r1[0], h2 = r2[0];
    if (h1->val <= h2->val) {
      dummy.next = h1;
      cur = h1;
      h1 = h1->next;
    } else {
      dummy.next = h2;
      cur = h2;
      h2 = h2->next;
    }

    while (h1 && h2) {
      if (h1->val <= h2->val) {
        cur->next = h1;
        h1 = h1->next;
      } else {
        cur->next = h2;
        h2 = h2->next;
      }
      cur = cur->next;
    }
    cur->next = h1 ? h1 : h2;
    while (cur->next)
      cur = cur->next;
    return {dummy.next, cur};
  }

  ListNode *sortList(ListNode *head) {
    int len = 0;
    ListNode *tmp = head;
    while (tmp) {
      tmp = tmp->next;
      len++;
    }
    vector<ListNode *> r = quick_sort(head, len);
    return r[0];
  }
};
int main() {
  Solution s;
  vector<int> v = {3, 1, 2, 3, 8, 4, 9};
  // v = {3, 1, 3};
  ListNode *l = buildChainTable(v);
  ListNode *r = s.sortList(l);
  ListNode *t1 = r;
  while (r) {
    cout << r->val << ", ";
    r = r->next;
  }
  while (t1) {
    ListNode *t = t1->next;
    delete t1;
    t1 = t;
  }
}
