class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        const int n = prices.size();
        vector<int> max_left(n, 0);
        vector<int> max_right(n, 0);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[i] >= prices[j]) continue;
                max_left[j] = max(max_left[j], profits[i]);
                max_right[i] = max(max_right[i], profits[j]);
            }
        }
        int ans = 0;
        for (int j = 1; j < n - 1; j++) {
            if (max_left[j] > 0 && max_right[j] > 0) {
                ans = max(ans, max_left[j] + max_right[j] + profits[j]);
            }
        }
        if (ans > 0) return ans;
        return -1;
    }
};

/*
1. In my solution, I focus on each middle item j. 
2. For every item j, I calculate max_left as the maximum of profits[i] for all i < j where prices[i] < prices[j], and I calculate max_right as the maximum of profits[k] for all k > j where prices[k] > prices[j].
3. After computing max_left and max_right, I iterate through j from 1 to n-2. Ans is determined as the maximum of max_left[j] + profits[j] + max_right[j]. If ans ends up being 0, I return -1; otherwise, I return ans. 
*/