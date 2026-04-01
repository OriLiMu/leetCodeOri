#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <pthread.h>
#include <stdexcept>
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
    ListNode *tmp = head;
    int n = 0;
    while (tmp) {
      n++;
      tmp = tmp->next;
    }
    ListNode dummy(0, head), *h1 = head, *h2 = head, *cur = &dummy,
                             *next = nullptr; // this head need process
    for (int l = 1; l < n; l *= 2) {
      // move h2 ahead
      cur = &dummy, h1 = cur->next,
      h2 = cur->next; // 这里有错误一开始没有初始化
      while (h1) {
        int m = n = l;
        // 需要断开, 断开需要一个prev指针
        // move h2
        while (m-- && h2)
          h2 = h2->next;
        next = h2;
        m = l;
        // save next ptr
        while (m-- && next)
          next = next->next;
        // tmp = tmp->next; // the tmp is not be nullptr here
        // tmp->next = nullptr; // 断了一个还差一个, 如果你想断开, 需要走过去,
        // 这样看计数好一些
        m = l;
        while (m && n && h1 && h2) {
          if (h1->val <= h2->val) {
            cur = cur->next = h1;
            h1 = h1->next;
            m--;
          } else {
            cur = cur->next = h2;
            h2 = h2->next;
            n--;
          }
        }

        while (m-- && h1) {
          cur = cur->next = h1;
          h1 = h1->next;
        }

        // 这里有问题, 你在这里没有赋值为nullptr, 所以这里直接出界
        while (n-- && h2) {
          cur = cur->next = h2;
          h2 = h2->next;
        }

        cur->next = nullptr;
        h1 = h2 = next; // 这里的问题还是我们要做断开,
                        // 那么就需要保存一开始的next指针
      }
    }

    return dummy.next;
  }
};

int main() {
  Solution s;
  vector<int> v = {3, 1};
  v = {5, 3, 4};
  ListNode *r = buildChainTable(v);
  ListNode *r2 = s.sortList(r);
  r = r2;
  while (r2) {
    cout << r2->val << ", ";
    r2 = r2->next;
  }
  while (r) {
    ListNode *t = r->next;
    delete r;
    r = t;
  }
}
