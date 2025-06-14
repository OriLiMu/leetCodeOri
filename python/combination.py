result = []
def combinations_dp(arr, prefix, start, k):
    if k == 0:
        return [[]]
    if len(prefix) == k:
        return result.append(prefix.copy()) # 这里的copy还是要注意
    for n in arr[start:]:
        #prefix = prefix + [n]
        prefix.append(n)
        start += 1
        combinations_dp(arr, prefix, start, k)
        prefix.pop()


arr = [1, 2, 3]
k = 2
start = 0
for p in arr:
    start += 1
    combinations_dp(arr, [p], start, 2)
print(result)