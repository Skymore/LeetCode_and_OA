#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
/*
 * 题意：给一个字符串，字符串里有26个小写字母，每个字母代表一个键盘上的按键。
 * 求如何安排键盘每个按键代表字母，使得输入该字符串时需要的按键次数最少。
 * 键盘有9个按键，每个按键可以代表至多3个字母。
 * Solution: 贪心算法
 */
int findMinClicks(string s) {
    map<char, int> cnt;
    for (char c : s) cnt[c]++;

    vector<int> freqs;
    for (auto &p : cnt) freqs.push_back(p.second);

    sort(freqs.rbegin(), freqs.rend());

    int res = 0;
    for (int i = 0; i < freqs.size(); ++i) res += (i / 9 + 1) * freqs[i];

    return res;
}

int main() {
    cout << findMinClicks("abacadefghibj") << endl;
    cout << "reference answer: 0" << endl;
    return 0;
}