class Solution
{
public:
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        for (int num : nums)
        {
            for (int t = target; t >= num; t--)
            {
                if (t - num == 0 || dp[t - num])
                {
                    dp[t] = max(dp[t], dp[t - num] + 1);
                }
            }
        }
        return dp[target] ? dp[target] : -1;
    }
};

/*
    This is a a variation of the 0/1 Knapsack problem where the “knapsack” (in this case, the target sum) must be exactly filled.
    The value of each number is 1 and the cost is the number itself.
*/