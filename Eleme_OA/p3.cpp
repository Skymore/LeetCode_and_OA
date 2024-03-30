#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 一维扫雷，雷的分布组合数
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            if (i + 1 < n && s[i + 1] == '?') {
                s[i + 1] = '*';
            }
            if (i - 1 >= 0 && s[i - 1] == '?') {
                s[i - 1] = '*';
            }
        }
        // $ 表示没有雷
        if (s[i] == '0') {
            if (i + 1 < n && s[i + 1] == '?') {
                s[i + 1] = '$';
            }
            if (i - 1 >= 0 && s[i - 1] == '?') {
                s[i - 1] = '$';
            }
        }
    }

    // 处理1两侧确定的情况
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            // 统计相邻雷的个数
            int star_cnt = 0;
            if (i + 1 < n && s[i + 1] == '*') {
                star_cnt++;
            }
            if (i - 1 >= 0 && s[i - 1] == '*') {
                star_cnt++;
            }
            int unknown_cnt = 0;
            if (i + 1 < n && s[i + 1] == '?') {
                unknown_cnt++;
            }
            if (i - 1 >= 0 && s[i - 1] == '?') {
                unknown_cnt++;
            }

            if (star_cnt == 1 && unknown_cnt == 1) {
                if (i + 1 < n && s[i + 1] == '?') {
                    s[i + 1] = '$';
                }
                if (i - 1 >= 0 && s[i - 1] == '?') {
                    s[i - 1] = '$';
                }
            }

            if (star_cnt == 0 && unknown_cnt == 1) {
                if (i + 1 < n && s[i + 1] == '?') {
                    s[i + 1] = '*';
                }
                if (i - 1 >= 0 && s[i - 1] == '?') {
                    s[i - 1] = '*';
                }
            }
        }
    }
    const int MODD = 1e9 + 7;
    // dp[i][0] 表示第 i 个位置没有雷的方案数
    // dp[i][1] 表示第 i 个位置有雷的方案数
    // 初始化 0 位置
    s = '$' + s;
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '*') {
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MODD;
            dp[i][0] = 0;
        }

        if (s[i] == '$' || isdigit(s[i])) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MODD;
            dp[i][1] = 0;
        }

        if (s[i] == '?') {
            if (s[i - 1] == '1') {
                if (i >= 2) {
                    dp[i][0] = dp[i - 2][1];
                    dp[i][1] = dp[i - 2][0];
                } else {
                    dp[i][0] = 0;
                    dp[i][1] = 1;
                }
            } else {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MODD;
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MODD;
            }
        }
    }

    cout << (dp[n][0] + dp[n][1]) % MODD << endl;
}