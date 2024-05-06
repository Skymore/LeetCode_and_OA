#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    vector<vector<int>> dp2(n+1, vector<int>(x+1, 0));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        b[i] = a[i] / 2;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[0][i] = 1000000;
        dp2[0][i] = 1000000;
    }
    int ans = 1000000;
    for (int i = 1; i <= n; i++) {
        //cout << "i: " << i << endl;
        for (int j = x; j >= 0; j--) {
            dp[i][j] = dp[i-1][j];
            if (j >= b[i-1]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-b[i-1]] + 1);
            }
            // 使用推荐两次，不推荐 a[i-1]
            dp2[i][j] = dp2[i-1][j];
            // 之前推荐了两次，推荐 a[i-1] 一次
            if (j >= b[i-1]) {
                dp2[i][j] = min(dp2[i][j], dp2[i-1][j-b[i-1]] + 1);
            }
            // 之前推荐了一次，推荐 a[i-1] 两次
            if (j >= a[i-1]) {
                dp2[i][j] = min(dp2[i][j], dp[i-1][j-a[i-1]] + 1);
            }
        }

        // for (int j = 0; j <= x; j++) {
        //     cout << dp[i][j] << " ";
        // }
        // cout << endl;
        // for (int j = 0; j <= x; j++) {
        //     cout << dp2[i][j] << " ";
        // }

    }
    ans = min(dp[n][x], dp2[n][x]);
    cout << ans << endl;

    //dp[i][j] 表示向前 i-1 个账号推荐，涨粉 j 个的最小花费，没用多次推荐
    //dp2[i][j] 表示向前 i-1 个账号推荐，涨粉 j 个的最小花费，用了多次推荐
    // dp[i][j] = dp[i-1][j-b[i]] + 1 选择推荐a[i]一次
    // dp[i][j] = dp[i-1][j] 选择不推荐a[i]
    // dp2[i][j] = dp2[i-1][j-b[i]] + 1
}