class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        map<int, int> mp;
        for (const int &n : nums) mp[n]++;


        // 遍历 map 寻找最小值
        int minc = INT_MAX;
        for (const auto& [value, count] : mp) minc = min(minc, v);
        int total_group;
        for (int i = minc; i >= 1; i--) {
            total_group = 0;
            bool is_valid = true;

            for (const auto [value, count] : mp) {
                int num_group = count / i;
                int remainder = count % i;
                if (remainder > num_group) {
                    is_valid = false;
                    break;
                }
                num_group = count / (i + 1);
                remainder = count % (i + 1);
                if (remainder > 0) {
                    num_group++;
                }
                total_group += num_group;
            }

            if (is_valid) {
                break;
            }
        }
        return total_group;
    }
};

/*
 * Firstly, I count the number of occurrences of each number in  "nums".
 * After that, I find the min frequency of any element in "nums" as minc.
 * Then I check all possible group size i of the smaller group. I iterate i from minc to 1.
 * During each iteration, for each [value, count] in mp. I initially try grouping
 *   them using the smaller group size 'i', forming num_group groups. if the remainder, which is
 *   the count of ungrouped elements, is greater than the number of formed groups, then this
 *   group size i is invalid. Otherwise, this group size i is valid for this value. I then use
 *   the larger group size 'i+1' to group them, forming num_group groups. If there's any remainder,
 *   I increment num_group. Then add num_group to total_group.
 * Finally, if a group size 'i' is validated across all elements, the loop terminates, and the total count of groups
 * is returned.
*/