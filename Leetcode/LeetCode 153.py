class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        left = 0
        right = len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        return nums[left]

# An array is sorted and then rotated.
# So I used binary search to find the min element
# 1. IF there is only one element in the array, return it
# 2. Set up two pointers, left and right, to track the start and the end of the array, respectively
# 3. Execute a binary search by a loop while left is less than right
# 4. Inside the loop:
#       Calculate the middle index mid
#       Check if nums[mid] is greater than nums[right].
#         If nums[mid] is greater than nums[right], the pivot point is in the right half of the array
#         Set right to mid + 1
#         Otherwise set right to mid
# 5.After the loop, left equals right, So nums[Left] is the pivot num
