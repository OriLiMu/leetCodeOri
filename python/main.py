def isSubsequence(seq: str, s: str) -> bool:
    it = iter(s)  # 将字符串 s 转换为迭代器
    for c in seq:  # 遍历 seq 中的每个字符
        try:
            while True:
                # 从迭代器中获取下一个字符
                current_char = next(it)
                if current_char == c:  # 如果找到匹配的字符
                    break  # 跳出循环，继续检查下一个字符
        except StopIteration:  # 如果迭代器耗尽
            return False  # seq 不是 s 的子序列
    return True  # seq 是 s 的子序列

