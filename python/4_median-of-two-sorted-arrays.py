from functools import total_ordering
from typing import List


class Solution:
    def findNth(
        self, nums1: list[int], s1: int, nums2: list[int], s2: int, k: int
    ) -> float:
        print(s1, s2, k)
        if len(nums1) - s1 > len(nums2) - s2:
            return self.findNth(nums2, s2, nums1, s1, k)
        else:
            if len(nums1) - 1 - s1 < 0:
                return nums2[s2 + k - 1]

            if k == 1:
                return min(nums1[s1], nums2[s2])

            last1 = nums1[min(len(nums1) - 1, s1 + k // 2 - 1)]
            l1CutCnt = k // 2
            # 这里没有定义 l2CutCnt就是个问题
            if k // 2 > len(nums1) - 1 - s1:
                l1CutCnt = len(nums1) - s1
            # 这里疏忽了 last2 是根据cutCnt1 的结果来算的
            last2 = nums2[s2 + k - l1CutCnt - 1]
            if last1 > last2:
                # 这里如果把l2CutCnt算出来更好, 这个还是一个很有意思的变量
                return self.findNth(nums1, s1, nums2, s2 + k - l1CutCnt, l1CutCnt)
            else:
                return self.findNth(nums1, s1 + l1CutCnt, nums2, s2, k - l1CutCnt)

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        total_len = len(nums1) + len(nums2)
        if total_len % 2 == 0:
            return (
                self.findNth(nums1, 0, nums2, 0, total_len // 2)
                + self.findNth(nums1, 0, nums2, 0, total_len // 2 + 1)
            ) / 2.0
        else:
            return self.findNth(nums1, 0, nums2, 0, total_len // 2 + 1)


if __name__ == "__main__":
    s = Solution()
    # print(s.findMedianSortedArrays([1, 3], [2]))
    # print(s.findMedianSortedArrays([1, 2], [3, 4]))
    # key case
    # print(s.findMedianSortedArrays([1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17]))
    # key case. 这个忽略了l1CutCnt的变化会影响 l2CutCnt. 这里的问题也许是对变量定义的错误
    print(s.findMedianSortedArrays([3], [1, 2, 4, 5, 6]))
