class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        Integer cand = null;
        int count = 0;
        for (int num: nums) {
            if (count == 0) {
                cand = num;
            }
            count += (num == cand)? 1 : -1;
        }
        return cand;
    }
}

// 如果一个数是majority element，那么它的出现次数一定比其他所有数的出现次数之和还要多，那么他最后一定会留下来