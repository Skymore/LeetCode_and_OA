class Solution {
   public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 3; k++) {
                if (i - k >= 0) {
                    dp[i] = min(dp[i], dp[i - k]);
                }
            }
            dp[i] += max(0, k - nums[i - 1]);
        }

        long long ans = LLONG_MAX;
        for (int k = 0; k <= 2; k++) {
            ans = min(ans, dp[n - k]);
        }
        return ans;
    }
};
/*
1. I used a dynamic programming approach, where dp[i] represents the minimum
number of operations required to make the subarray nums[0..i-1] "beautiful",
with an additional condition that nums[i-1] is greater than or equal to k.
2. I iterated through the nums array (1-indexed in the dp array). For each
element at index i-1, I considered up to 3 previous elements (if they exist) and
chose the minimum number of operations required to ensure that the subarray
nums[0..i-2] is beautiful.
3. I added the number of operations required to make nums[i-1] at least k to dp[i].
4. After the dp array was calculated, the answer should be the minimum of the
last three elements of the dp array, which corresponds to considering subarrays
of length n, n-1, and n-2.
*/