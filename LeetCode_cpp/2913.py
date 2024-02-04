class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for start in range(n):
            st = set()
            for end in range(start, n):
                st.add(nums[end])
                ans += len(st) * len(st)
        return ans