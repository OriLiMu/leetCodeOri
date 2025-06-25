class Solution:
    def findKth(self, nums1, s1, nums2, s2, k):
        if len(nums1) - s1 > len(nums2) - s2:
            return self.findKth(nums2, s2, nums1, s1, k)
        if s1 > len(nums1) - 1:
            return nums2[s2 + k - 1]
        if k == 1:
            return min(nums1[s1], nums2[s2])

        # 我本想算的是把第一个数组中欠的长度全推给数组2, 实际上有可能引起越界
        kth_index1 = min(s1 + k // 2 - 1, len(nums1) - 1)
        kth_index2 = k - (kth_index1 - s1 + 1) - 1 + s2
        if nums1[kth_index1] > nums2[kth_index2]:
            return self.findKth(
                nums1, s1, nums2, kth_index2 + 1, k - (kth_index2 - s2) - 1
            )
        else:
            return self.findKth(
                nums1, kth_index1 + 1, nums2, s2, k - (kth_index1 - s1) - 1
            )

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1 = len(nums1)
        l2 = len(nums2)
        l = l1 + l2
        if l % 2 == 0:
            return (
                self.findKth(nums1, 0, nums2, 0, l // 2)
                + self.findKth(nums1, 0, nums2, 0, l // 2 + 1)
            ) / 2.0
        else:
            return self.findKth(nums1, 0, nums2, 0, l // 2 + 1)
