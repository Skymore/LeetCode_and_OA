class Solution {
    int lower_bound(int[] nums, int t) {
        int ll = 0;
        int rr = nums.length - 1;

        while (ll <= rr) {
            int mid = ll + (rr - ll) / 2;
            if (nums[mid] >= t) {
                rr = mid - 1;
            } else {
                ll = mid + 1;
            }
        }
        return ll;
    }

    int upper_bound(int[] nums, int t) {
        int ll = 0;
        int rr = nums.length - 1;
        while (ll <= rr) {
            int mid = ll + (rr - ll) / 2;
            if (nums[mid] > t) {
                rr = mid - 1;
            } else {
                ll = mid + 1;
            }
        }
        return ll;
    }
    public boolean isMajorityElement(int[] nums, int t) {
        int low = lower_bound(nums, t);
        int up = upper_bound(nums, t);
        return up - low > nums.length / 2;
    }
}