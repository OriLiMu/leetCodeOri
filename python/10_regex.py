from operator import truediv
from tempfile import TemporaryFile
import types


class Solution:
    def regexMatch(self, s, s1, p, s2):
        next_char = None
        if next_char and len(s) - 1 >= s1 + 1:
            next_char = s[s + 1]
        if next_char == "*":
            return
        else:
            return s[s1] == p[s2]

    def isMatch(self, s: str, p: str) -> bool:
        self.regexMatch(s, 0, p, 0)
        return True
