#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<map<int, int>> dp(n);
        int maxx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxx) maxx = nums[i];
        }
        long long ans = 0;
        vector<long long> index;
        index.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxx) {
                index.push_back(i);
            }
        }
        int last = -1;
        for (int i = k-1; i < index.size(); i++) {
            ans += (index[i-k+1] - last) * (n-1-index[i]+1);
            last = index[i-k+1];
        }
        return ans;
    }
};

