from typing import List

class Solution:
    def prefix_function(s: List[int]) -> List[int]:
        n = len(s)
        pi = [0] * n
        for i in range(1, n):
            j = pi[i - 1]
            while j > 0 and s[i] != s[j]:
                j = pi[j - 1]
            if s[i] == s[j]:
                j += 1
            pi[i] = j
        return pi

    def find_occurrences(t: List[int], s: List[int]) -> List[int]:
        cur = s + [-2] + t  # Use -2 as a separator that won't appear in input
        sz1, sz2 = len(t), len(s)
        ret = []
        lps = Solution.prefix_function(cur)
        for i in range(sz2 + 1, sz1 + sz2 + 1):
            if lps[i] == sz2:
                ret.append(i - 2 * sz2)
        return ret

    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        # Calculate the difference pattern in nums
        d = [(nums[i+1] - nums[i]) // abs(nums[i+1] - nums[i]) if nums[i+1] != nums[i] else 0 for i in range(len(nums) - 1)]
        ans = len(self.find_occurrences(d, pattern))
        return ans
