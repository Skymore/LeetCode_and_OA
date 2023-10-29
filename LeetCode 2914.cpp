class Solution {
   public:
    int minChanges(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, INT_MAX));
        dp[0][0] = dp[0][1] = 0;

        for (int i = 2; i <= n; i += 2) {
            int ones = 0, zeros = 0;
            for (int j = i - 2; j < i; ++j) {
                if (s[j] == '1')
                    ++ones;
                else
                    ++zeros;
            }

            for (int cur = 0; cur < 2; ++cur) {
                for (int last = 0; last < 2; ++last) {
                    int cost = (cur == 0) ? ones : zeros;
                    dp[i][cur] = min(dp[i][cur], dp[i - 2][last] + cost);
                }
            }
        }

        return min(dp[n][0], dp[n][1]);
    }
};
/*

1. I used a dynamic programming approach where dp[i][j] representes the mininum number of changes required to make the prefix s[0..i-1] beautiful, with the last substring ending in j (0 or 1).
2. I iterated throught the string with a step size of 2, considering pairs of characters at a time.
3. For each pair, calculate the number of '1's and '0's
4. Here, 'cur' represents the ending number of the new pair, and 'last' represents the ending number of the previous pair. Both 'cur' and 'last' can be 0 or 1. So, I calculated  the cost to change the new pair into all possible 'cur' values.
5. Finally, return min(dp[n][0], dp[n][1])
*/