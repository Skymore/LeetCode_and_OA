class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int count1 = 0, count2 = 0;
        Integer cand1 = null;
        Integer cand2 = null;
        for (int n: nums) {
            if (cand1 != null && cand1 == n) {
                count1++;
            } else if (cand2 != null && cand2 == n) {
                count2++;
            } else if (count1 == 0) {
                cand1 = n;
                count1++;
            } else if (count2 == 0) {
                cand2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        List<Integer> res = new ArrayList<>();
        count1 = 0;
        count2 = 0;
        for (int n: nums) {
            if (cand1 != null && n == cand1) count1++;
            if (cand2 != null && n == cand2) count2++;
        }

        int n = nums.length;
        if (count1 > n / 3) res.add(cand1);
        if (count2 > n / 3) res.add(cand2);

        return res;

    }
}
// 229. Majority Element II
// 给定一个大小为n的数组，找到所有出现次数大于n/3的元素


// 用摩尔投票法
// 如果一个数的出现次数大于n/3，那么最多只能有两个这样的数
// 用两个变量cand1和cand2来记录两个候选数，count1和count2来记录它们的出现次数
// 遍历数组，如果当前数和cand1相等，count1++，如果和cand2相等，count2++，如果count1为0，cand1等于当前数，count1++，如果count2为0，cand2等于当前数，count2++，如果当前数和cand1和cand2都不相等，那么cand1和cand2的count都减一
// 遍历完数组后，再来一次遍历，统计cand1和cand2的出现次数，如果大于n/3，加入结果集
// 时间复杂度O(n)，空间复杂度O(1)

// 最后的两个数不一定是出现次数最多的两个数，但是如果一个数出现次数大于n/3，那么它一定会留下来
