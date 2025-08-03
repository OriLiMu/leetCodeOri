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

class Solution {
public:
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

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = dummy;
    ListNode *tmp, *next, *last;
    while (true) {
      last = cur->next;
      tmp = cur->next;
      for (int i = 0; i < k; i++, tmp = tmp->next) {
        if (!tmp)
          return dummy->next;
      }
      if (cur->next) {
        cur->next->next = tmp;
        cur = cur->next;
      } else {
        return dummy->next;
      }
      for (int i = 0; i < k - 1; i++) {
        if (cur->next) {
          next = cur->next->next;
          cur->next->next = cur;
          cur = next;
        }
      }
      last->next = tmp;
      cur = last;
    }

    return dummy->next;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 3;
  ListNode *head = s.buildChainTable(nums);
  s.reverseKGroup(head, k);
  while (head) {
    cout << head->val << ", ";
    head = head->next;
  }
}
