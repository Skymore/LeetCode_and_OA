class Solution {
   public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int count = 0;
            for (int num : nums) {
                if ((num & (1 << i)) != 0)
                    count++;
            }
            // cout << count << endl;
            if (count >= k) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

/*
Brute force:
For each bit from 0 to 31, traverse the nums and count the number of '1's in
this bit of all elements in the nums. if count >= k, then add this bit of ans
is 1.
*/