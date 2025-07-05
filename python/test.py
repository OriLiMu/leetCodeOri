import random

def quick_sort_optimized(arr, low, high):
    if low < high:
        pivot_idx = partition_optimized(arr, low, high)
        quick_sort_optimized(arr, low, pivot_idx - 1)
        quick_sort_optimized(arr, pivot_idx + 1, high)

def partition_optimized(arr, low, high):
    # 尝试找到 0 的位置
    zero_pos = -1
    for i in range(low, high + 1):
        if arr[i] == 0:
            zero_pos = i
            break

    # 如果存在 0，优先选 0 作为 pivot；否则随机选择
    if zero_pos != -1:
        pivot = 0
        pivot_pos = zero_pos
    else:
        pivot_pos = random.randint(low, high)
        pivot = arr[pivot_pos]

    # 交换 pivot 到最右侧
    arr[pivot_pos], arr[high] = arr[high], arr[pivot_pos]

    # 标准分区逻辑
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


# 测试
arr = [10, 7, 0, 8, 9, 1, 5]
quick_sort_optimized(arr, 0, len(arr) - 1)
print("优化后的排序结果:", arr)  # 输出: [0, 1, 5, 7, 8, 9, 10]
