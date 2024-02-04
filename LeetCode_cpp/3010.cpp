#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minv = INT_MAX;
        int min2v = INT_MAX;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < minv) {
                min2v = minv;
                minv = nums[i];
            }
            else if (nums[i] < min2v) min2v = nums[i];
        }
        return nums[0] + minv + min2v;
    }
};

/*
 * 3010. Divide an Array Into Subarrays With Minimum Cost I
 */