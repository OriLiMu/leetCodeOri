# -*- coding: utf-8 -*-
from typing import List
from random import randint

class Solution:
    def setOne(self, nums, l, r, k):
        if l == r:
            return nums[k]
        left =  l - 1
        right = r + 1
        pivot_idx = l
        # 先移动完再比较
        while right > left:
            left += 1
            while nums[left] < nums[pivot_idx]:
                left += 1
            right -= 1
            while nums[right] > nums[pivot_idx]:
                right -= 1
            if right > left:
                nums[right], nums[left] = nums[left], nums[right]

        if right < k:
            return self.setOne(nums, right + 1, r, k)
        else:
            return self.setOne(nums, l, right, k)


    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.setOne(nums, 0, len(nums) - 1, len(nums) - k)


if __name__ == "__main__":
    nums = [5,2,4,1,3,6,0]
    k = 4
    s = Solution()
    print(s.findKthLargest(nums, k))
