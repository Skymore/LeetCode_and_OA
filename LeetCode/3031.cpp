class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    int minimumTimeToInitialState(string word, int k) {
        auto p = prefix_function(word);
        int n = word.size(); // 字符串长度

        for (int i = k; i <= n; i += k) {
            // 比较从第i+1个字符开始的子字符串与开头的子字符串的哈希值
            if (get_hash(i + 1, n) == get_hash(1, n-i)) {
                return i / k; // 如果匹配，返回需要移动的次数
            }
        }

        // 如果没有匹配
        return (n + k - 1) / k;
    }
};
