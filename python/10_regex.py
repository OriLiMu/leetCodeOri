# -*- coding: utf-8 -*-
from operator import truediv
from tempfile import TemporaryFile
import types


class Solution:
    def __init__(self):
        result_matrix = []

    def regexMatch(self, origin_s, s1, pat, s2):
        if s1 > len(origin_s) - 1 and s2 >= len(pat):
            return True
        elif s1 < len(origin_s) and s2 >= len(pat):
            return False
        elif s1 > len(origin_s) - 1 and s2 < len(pat):
            while s2 < len(pat):
                if s2 + 1 >= len(pat) or pat[s2 + 1] != '*':
                    return False
                s2 += 2
            return True

        if self.result_matrix[s1][s2] != -1:
            return True if self.result_matrix[s1][s2] == 1 else False

        cur_char = pat[s2]
        next_char = None
        if s2 + 1 < len(pat):
            next_char = pat[s2 + 1]
        if next_char and next_char == "*":
            for idx in range(s1, len(origin_s) + 1):
                if idx != s1 and cur_char != '.' and cur_char != origin_s[idx - 1]:  # 这里的逻辑略微有些复杂, 但是这里没问题
                    self.result_matrix[s1][s2] = 0
                    return False
                if self.regexMatch(origin_s, idx, pat, s2 + 2):
                    self.result_matrix[s1][s2] = 1
                    return True
            return False
        else:
            if origin_s[s1] == pat[s2] or pat[s2] == '.':  # 忘记了单点的计算
                return self.regexMatch(origin_s, s1 + 1, pat, s2 + 1)
            else:
                self.result_matrix[s1][s2] = 0
                return False

    def isMatch(self, s: str, p: str) -> bool:
        self.result_matrix = [[-1 for _ in range(len(p))] for _ in range(len(s))]
        return self.regexMatch(s, 0, p, 0)


if __name__ == "__main__":
    s = Solution()
    print(s.isMatch('abbb', '.*'))  # T
    print(s.isMatch('aa', 'b*'))  # F
    print(s.isMatch('aab', 'b*'))  # F
    print(s.isMatch('aabbb', 'a*b*'))  # T
    print(s.isMatch('aabbaa', 'a*b*a*'))  # T

    print(s.isMatch('abbb', '.*'))  # T
    print(s.isMatch('abbb', 'a*d*'))  # F

    print(s.isMatch('abcdddbb', 'aba*a*.*c*b*b'))  # F
    print(s.isMatch('', 'a*.*c*b*'))  # F
