class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        left_min = 0
        left_max = 0
        for i in range(indexDifference, len(nums)):
            if nums[i - indexDifference] < nums[left_min]:
                left_min = i - indexDifference
            if nums[i - indexDifference] > nums[left_max]:
                left_max = i - indexDifference

            if nums[i] - nums[left_min] >= valueDifference:
                return [left_min, i]
            if nums[left_max] - nums[i] >= valueDifference:
                return [left_max, i]

        return [-1, -1]


"""
1.Firstly, I initialized two variables 'left_min' and 'left_max' to keep track of the indices where the minimum and
    maximum values within nums[0] to nums[i - indexDifference]
2.I started iterating through the array from the position indexDifference to the end of the array.
3.During each iteration, if the difference between the current element and minimum or maximum is greater than 
    valueDifference, this pair of elements meets the criteria, so return the index of current element and left_min or 
    left_max
O(n):By doing this, we're efficiently using a single pass through the array to find our answer, 
    which gives us a time complexity of O(n), since each element is considered exactly once.
"""