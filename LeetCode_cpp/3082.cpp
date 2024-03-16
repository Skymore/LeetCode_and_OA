class Solution {
public:
    typedef unsigned long long ull;
    const ull MOD = 1e9 + 7;

    ull fast_power(ull base, int exponent) {
        if (exponent == 0) return 1;
        ull result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }

    int sumOfPower(std::vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<ull>> dp(n + 1, vector<ull>(k + 1, 0));
        dp[0][0] = 1; 
        

        for(int i = 0; i < n; ++i) {
            // 从后向前遍历，避免干扰还未更新的状态
            for(int length = n; length > 0; --length) {
                for(int sum_ = k; sum_ >= nums[i]; --sum_) {
                    dp[length][sum_] += dp[length-1][sum_ - nums[i]];
                    dp[length][sum_] %= MOD; 
                }
            }
        }
        
        
        ull ans = 0;
        for (int length = n; length > 0; --length) {
            ull p = fast_power(2, n - length);
            ans += (p * dp[length][k]) % MOD;
            ans %= MOD;
        }
        
        return ans;
        
    }
};