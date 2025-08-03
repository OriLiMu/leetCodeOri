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

// Build the chain table from a vector
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
  vector<ListNode *> quick_sort(ListNode *head) {
    if (!head)
      return {nullptr, nullptr};
    if (!head->next)
      return {head, head};
    ListNode *pivot = head, *left = head, *iter = head->next, *preIter = head;
    while (iter) {
      if (iter->val < pivot->val) {
        ListNode *tmp1 = left->next;
        ListNode *tmp2 = iter->next;
        left->next = iter;
        left = iter;
        iter->next = tmp1;
        iter = tmp2;
        preIter->next = iter;
      } else {
        preIter = iter;
        iter = iter->next;
      }
    }

    ListNode *tmp = left->next;
    ListNode *h1 = head->next;
    ListNode *h2 = left->next;
    left->next = nullptr;
    vector<ListNode *> r1 = quick_sort(h1);
    vector<ListNode *> r2 = quick_sort(h2);
    if (r1[1])
      r1[1]->next = pivot;
    if (r2[0])
      pivot->next = r2[0];

    return {r1[0], r2[1]};
  }

  ListNode *sortList(ListNode *head) {
    vector<ListNode *> r = quick_sort(head);
    return r[0];
  }
};
int main() {
  Solution s;
  vector<int> v = {3};
  ListNode *l = buildChainTable(v);
  ListNode *l1 = s.sortList(l);
  ListNode *cur = l1;
  while (cur) {
    cout << cur->val << endl;
    cur = cur->next;
  }
}
