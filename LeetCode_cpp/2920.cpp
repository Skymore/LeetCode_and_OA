class Solution {
   public:
    // 2^10 = 1024 2^11 = 2048 2^12 = 4096 2^13 = 8096 2^14 = 16192
    int search(int i, int pre, int bits, int k, vector<int>& coins, vector<vector<int>>& g, vector<vector<int>>& dp) {
        if (bits >= 14)
            return 0;
        if (dp[i][bits] != -1)
            return dp[i][bits];
        int way1 = (coins[i] >> bits) - k, way2 = coins[i] >> (bits + 1);
        for (int j : g[i]) {
            if (j == pre)
                continue;
            way1 += search(j, i, bits, k, coins, g, dp);
            way2 += search(j, i, bits + 1, k, coins, g, dp);
        }
        dp[i][bits] = max(way1, way2);
        return dp[i][bits];
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        const int n = coins.size();
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }

        vector<vector<int>> dp(n, vector<int>(14, -1));
        return search(0, -1, 0, k, coins, g, dp);
    }
};

// Top-down approach using memoization and TreeDP.
// 1. For each node i, there are two ways to collect coins:
//      - way1: Collect coins[i] - k without affecting the children's coins.
//      - way2: Collect coins[i] >> 1 (i.e., coins[i] / 2), but the coins of the children will be halved.
// 2. Use "bits" to track the cumulative halving actions from ancestors, shifting the coins right by "bits" positions in the subtree rooted at node i.
// 3. Notice that after 14 bit shifts, no coin will be left because even the largest possible number of coins will become 0.
// 4. Apply a recursive search with memoization. Each node will recursively check two options and the result will be stored to avoid redundant calculations.
// 5. The answer is obtained by calling search(0, -1, 0), starting from the root node with no parent (-1) and no previous bit shifts (0).