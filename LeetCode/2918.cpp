class Solution {
   public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeros1 = 0, zeros2 = 0;
        long long sum1 = 0, sum2 = 0;
        for (int num1 : nums1) {
            sum1 += num1;
            if (num1 == 0)
                zeros1++;
        }
        for (int num2 : nums2) {
            sum2 += num2;
            if (num2 == 0)
                zeros2++;
        }
        long long min1 = sum1 + zeros1;
        long long min2 = sum2 + zeros2;
        if (min1 == min2)
            return min2;
        long long ans;
        if (min1 > min2 && zeros2 > 0) {
            ans = min1;
        } else if (min2 > min1 && zeros1 > 0{
            ans = min2;
        } else {
            ans = -1;
        }
        return ans;
    }
};

/*
1. Calculate the total sum of both nums1 and nums2, as sum1 and sum2, and count
the number of zeros in nums1 and nums2, as zeros1 and zeros2.
2. As a result, the potential minimum total sum of nums1 is min1, calculated as
sum1 + zeros1. The same calculation applies to min2.
3. If min1 is equal to min2, then the answer is min1.
4. Otherwise, if min1 > min2, and zeros2 > 0, which is there is at least one
zero in nums2, So I can increment the zero such that sum of nums2 equals to sum
of nums1.
5. Similarly, if min2 > min1, the same logic applies.
5. Otherwise, the ans is -1.

*/