class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_left(n, INT_MAX), min_right(n, INT_MAX);
        min_left[0] = nums[0];
        min_right[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            min_left[i] = min(min_left[i-1], nums[i-1]);
        }
        int ans = INT_MAX;
        for (int i = n-2; i >= 0; i--) {
            min_right[i] = min(min_right[i+1], nums[i+1]);
            if (min_left[i] < nums[i]  && min_right[i] < nums[i]) {
                ans = min(ans, min_left[i] + min_right[i] + nums[i]);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};