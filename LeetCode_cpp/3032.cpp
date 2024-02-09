class Solution {
public:
    int numberCount(int a, int b) {
        int count = 0;
        for (int i = a; i <= b; ++i) {
            string numStr = to_string(i);
            set<char> uniqueDigits(numStr.begin(), numStr.end());

            // 如果数字的字符串表示的长度等于集合中不重复元素的数量，则计数增加
            if (numStr.length() == uniqueDigits.size()) {
                ++count;
            }
        }
        return count;
    }
};