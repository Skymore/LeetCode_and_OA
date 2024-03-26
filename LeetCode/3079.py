class Solution:
    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        ans = 0;
        for num in nums:
            num = str(num)
            max_digit = max(num)
            
            for i in range(len(num)):
                ans += int(max_digit) * (10 ** i)
        return ans