def min_swaps(nums):
    mp = {}#记录排序后的正确位置
    sort_nums = sorted(nums)
    for i in range(len(sort_nums)):
        mp[sort_nums[i]]=i

    lops = 0
    flags = []

    for i in range(len(nums)):
        flags.append(False)
    for i in range(len(nums)):
        if not flags[i]:
            j = i
            while not flags[j]:
                flags[j] = True
                j = mp[nums[j]]
            lops += 1
    '''
    //假设数组的循环节个数为lops
    最小交换次数min_swaps = len(A) - lops
    '''
    return len(nums) - lops

def min_swap(nums):
    pos = {}
    for i, num in enumerate(nums):
        pos[num] = i
    ans = 0
    for (i, num) in enumerate(nums):
        if num != i+1:
            nums[pos[i+1]], nums[i] = nums[i], nums[pos[i+1]]
            pos[num] = pos[i+1]
            pos[i+1] = i
            ans += 1
    
    return ans

    
# 随机生成n个数的排列
import random
from tqdm import tqdm
for i in tqdm(range(100000)):
    n = 10000
    nums = [i+1 for i in range(n)]
    random.shuffle(nums)

    if min_swaps(nums) != min_swap(nums):
        print("error")
        print(nums)
        break

print("done")