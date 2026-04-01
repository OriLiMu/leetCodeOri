#include <algorithm>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode dummy;
    ListNode *cur = &dummy;
    int tmp = 0;
    int cnt = 0;
    int v1, v2;
    while (l1 || l2 || carry) {
      v1 = l1 ? l1->val : 0;
      v2 = l2 ? l2->val : 0;
      tmp = (v1 + v2 + carry) % 10;
      carry = (v1 + v2 + carry) / 10;
      cur->next = new ListNode(tmp);
      cur = cur->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    return dummy.next;
  }
};

int main() {
  Solution s;
  vector<int> v1 = {2, 4, 3};
  vector<int> v2 = {5, 6, 4};
  ListNode *l1 = buildChainTable(v1);
  ListNode *l2 = buildChainTable(v2);
  ListNode *r = s.addTwoNumbers(l1, l2);
  cout << "I am here" << endl;
  int cnt = 0;
  while (r != NULL) {
    cout << r->val << ", ";
    r = r->next;
  }
}
