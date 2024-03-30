#include <iostream>
#include <vector>

using namespace std;

/*
 * 题目描述：给定一个字符串和一个包含字母及单个星号（*）的正则表达式，其中*代表零个或多个字符，找出字符串中最长且符合正则表达式的子串长度。
 * 约束条件：1 <= |text|, |regex| <= 10^6
 * 示例：
 * getLongestMatch("hackerrank", "ack*r") = 6
 * getLongestMatch("hackerrank", "ack*") = 9
 * getLongestMatch("hackerrank", "*ack") = 4
 * Solution: KMP算法 + 贪心算法 注意边界条件（*在开头或结尾）
 */

vector<int> prefix_function(string pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j += 1;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(string text, string pattern) {
    vector<int> pi = prefix_function(pattern);
    int n = text.size();
    int m = pattern.size();
    vector<int> match;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j += 1;
        }
        if (j == m) {
            match.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return match;
}

int getLongestMatch(string t, string p) {
    int star = p.find('*');

    string pre = p.substr(0, star);
    string suf = p.substr(star + 1);

    if (pre.empty() && suf.empty()) return t.size();

    if (pre.empty()) {
        auto suf_match = kmp(t, suf);
        if (suf_match.empty()) return -1;
        return suf_match.back() + suf.size();
    }

    if (suf.empty()) {
        auto pre_match = kmp(t, pre);
        if (pre_match.empty()) return -1;
        return t.size() - pre_match.front();
    }

    auto pre_match = kmp(t, pre);
    auto suf_match = kmp(t, suf);
    if (pre_match.empty() || suf_match.empty()) return -1;
    return suf_match.back() - pre_match.front() + suf.size();
}

int main() {
    cout << getLongestMatch("hackerrank", "ack*r") << endl;
    cout << getLongestMatch("hackerrank", "ack*") << endl;
    cout << getLongestMatch("hackerrank", "*ack") << endl;
    return 0;
}