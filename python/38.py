class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        s = '1'
        for _ in range(n - 1):
            cur_char = s[0]
            cur_count = 1
            ans = ''
            for c in s[1:]:
                if c == cur_char:
                    cur_count += 1
                else:
                    ans += str(cur_count) + str(cur_char)
                    cur_char = c
                    cur_count = 1
            ans += str(cur_count) + str(cur_char)
            s = ans
        return s

if __name__ == "__main__":
    s = Solution()
    print(s.countAndSay(4))
