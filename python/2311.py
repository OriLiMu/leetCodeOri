import copy


class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        n = int(s, 2)
        result = len(s)
        remove_cnt = 0
        for i, v in enumerate(s):
            if n <= k:
                break
            if v == '1':
                # print(1 << len(s) - i - 1)
                # print('xxx')
                n -= 1 << len(s) - i - 1
                remove_cnt += 1

        return len(s) - remove_cnt


if __name__ == "__main__":
    s = Solution()
    print(s.longestSubsequence('1001010', 5)) # 5
    print(s.longestSubsequence('00101001', 1)) # 6
