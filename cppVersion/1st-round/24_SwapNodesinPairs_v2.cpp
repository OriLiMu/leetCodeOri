#include <algorithm>
#include <chrono>
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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *pre = dummy, *a = pre->next, *b = a->next, *tmp;
    dummy->next = head;
    while (a && b) {
      tmp = b->next;
      pre->next = b;
      b->next = a;
      a->next = tmp;
      pre = a;
      a = a->next;
      if (!a)
        break;
      b = a->next;
    }

    return dummy->next;
  }
};
int main() {
  Solution s;
  vector<int> v = {1, 2, 3, 4};
  ListNode *c = buildChainTable(v);
  ListNode *p = s.swapPairs(c);
  cout << "lizhe" << endl;
}
