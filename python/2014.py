
class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        l1 = [[] for _ in range(26)]
        for i, v in enumerate(s):
            l1[ord(v) - ord('a')].append(i)

        if all(len(v) < k for v in l1):
            return ''
        curMax = ''
        for l in l1:
            if len(l) >= k:
                curMax = s[l[0]]
        d = {}
        for tl in l1:
            if len(tl) < k:
                continue
            cur_offset = 0
            d[s[tl[0]]] = len(tl)
            while True:
                attl = []
                cur_offset += 1
                if tl[-1] + cur_offset > len(s):
                    break
                for i in tl:
                    lk = s[i: i + cur_offset - 1]
                    ck = s[i: i + cur_offset]
                    if lk in d and d[lk] >= k:
                        if ck in d:
                            d[ck] += 1
                        else:
                            d[ck] = 1
                            attl.append(ck)
                if all(len(v) < k for v in attl):
                    break
        if len(curMax) == 0:
            return ''
        for key, v in d.items():
            if v >= k and key > curMax:
                curMax = key

        return curMax


if __name__ == '__main__':
    s = Solution()
    # print(s.longestSubsequenceRepeatedK('bb', 2))
    print(s.longestSubsequenceRepeatedK('letsleetcode', 2))




