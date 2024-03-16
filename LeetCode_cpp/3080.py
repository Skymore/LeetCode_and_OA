class Solution:
    def unmarkedSumArray(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        marked = [False] * n
        total = sum(nums)
        ans = []       
        heap = [(num, i) for i, num in enumerate(nums)]
        heapq.heapify(heap)
            
        for index, k in queries:
            if not marked[index]:
                marked[index] = True
                total -= nums[index]

            while k > 0 and heap:
                value, idx = heapq.heappop(heap)
                if not marked[idx]:
                    marked[idx] = True
                    total -= nums[idx]
                    k -= 1

            ans.append(total)
        
        return ans