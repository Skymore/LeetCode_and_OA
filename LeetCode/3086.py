class Solution:
    def minimumMoves(self, nums: List[int], k: int, max_changes: int) -> int:
        one_indexes = [index for index in range(len(nums)) if nums[index] == 1]
        min_moves = float('inf')
        if max_changes >= k:
            min_moves = 2 * k
        
        prefix = one_indexes.copy()
        for i in range(1, len(one_indexes)):
            prefix[i] += prefix[i - 1]
            
        def get_sum(left, right):
            if left > right:
                return 0
            if left == 0:
                return prefix[right]
            return prefix[right] - prefix[left - 1]
        
        num_step2 = max(1, k - max_changes)

        # step1: set an adjacent zero to one and swap with it
        # step2: pick the one at index x, with |y-x| moves, y is where dylan stands

        # Ones is the number of times using step 2, We can also consider the start of the game as step 2.
        for ones in range(num_step2, num_step2 + 3):
            if ones > k:
                break
            
            for left in range(0, len(one_indexes)):
                right = left + ones - 1
                if right >= len(one_indexes):
                    break
                
                curr_moves = (k - ones) * 2 # moves using step1
                mid = (right + left) // 2
                curr_moves += get_sum(mid + 1, right) - (right - mid) * one_indexes[mid]
                curr_moves += (mid - left) * one_indexes[mid] - get_sum(left, mid - 1)
                    
                min_moves = min(min_moves, curr_moves)
                
        return min_moves