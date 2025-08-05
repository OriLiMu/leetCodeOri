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
    int len = 0;
    ListNode *tmp = head;
    while (tmp) {
      len++;
      tmp = tmp->next;
    }

    ListNode dummy(0, head), *prev = &dummy, *h1 = head, *h2 = h1,
                             *next = nullptr;
    for (int l = 1; l < len; l *= 2) {
      prev = &dummy, h1 = h2 = head; // 这个部分的init忘了
      while (h1 || h2) {
        tmp = prev; // 这个还没有接到链表上后面都是空的
        int tl = l;
        while (tl-- && tmp)
          tmp = tmp->next;
        if (tmp) {
          h2 = tmp->next;
          tmp->next = nullptr;
        }
        tmp = h2;
        tl = l - 1;
        while (tl-- > 0 && tmp)
          tmp = tmp->next;
        next = tmp ? tmp->next : tmp;
        if (tmp)
          tmp->next = nullptr;

        ListNode *cur = prev;
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
        // 最后这两个地方的代码还是补全了,
        // 问题就是不能过于依赖某种逻辑的成立你的代码才是有效的,
        // 这个前提去写代码, 而是扎扎实实不能留弱点
        while (h1) {
          cur->next = h1;
          cur = cur->next;
          h1 = h1->next;
        }

        while (h2) {
          cur->next = h2;
          cur = cur->next;
          h2 = h2->next;
        }
        prev = cur;
        h1 = h2 = cur->next = next;
      }
    }
    return dummy.next;
  }
};

int main() {
  Solution s;
  vector<int> v = {3, 1, 2, 3, 8, 4, 9};
  v = {3, 8, 4, 9};
  v = {-1, 5, 3, 4, 0};
  // v = {1, 2};
  // v = {3, 1};
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
