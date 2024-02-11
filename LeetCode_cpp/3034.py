from typing import List

class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        # Calculate the difference pattern in nums
        d = [(nums[i+1] - nums[i]) // abs(nums[i+1] - nums[i]) if nums[i+1] != nums[i] else 0 for i in range(len(nums) - 1)]

        ans = 0
        # Iterate through the nums list to find matching subarrays
        for i in range(len(nums) - len(pattern)):
            flag = True
            # Check if the current subarray matches the pattern
            for j in range(len(pattern)):
                if d[i + j] != pattern[j]:
                    flag = False
                    break
            if flag:
                ans += 1
        return ans
