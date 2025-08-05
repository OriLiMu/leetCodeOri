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
  ListNode *sortList(ListNode *head) {
    if (!head)
      return head;
    int len = 0;
    ListNode *cur = head;
    while (cur) {
      len++;
      cur = cur->next;
    }

    ListNode *h1 = head, *h2 = h1, dummy(0, nullptr), *prev = &dummy;
    for (int l = 1; l < len; l *= 2) {
      int tl = l;
      cur = prev;
      while (tl-- && h2)
        h2 = h2->next;
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
      while (h1) {
        cur->next = h1;
        h1 = h1->next;
        cur = cur->next;
      }
      while (h2) {
        cur->next = h2;
        h2 = h2->next;
        cur = cur->next;
      }
      prev = cur;
      h1 = cur->next;
      h2 = h1;
    }

    return dummy.next;
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
