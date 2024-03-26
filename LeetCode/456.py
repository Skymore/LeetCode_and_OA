class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        stack = []
        s3 = float("-inf") 
        # s3 is the 3rd number in the pattern
        # we make sure that s3 is the largest number that forms a 3 2 pattern
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] < s3:
                return True
            else:
                # while the stack is not empty and the current number is greater than the top of the stack
                # the current number and the top of the stack can form a 3 2 pattern
                # so we update s3 to be the maximum of s3 and the top of the stack
                # we make sure that s3 is the largest number that forms a 3 2 pattern
                while stack and nums[i] > stack[-1]:
                    s3 = max(s3, stack.pop())
                stack.append(nums[i])
        return False

# Time Complexity: O(n)