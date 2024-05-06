#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = long long;
const int inf = 0x3f3f3f3f;


int maxScore(const vector<int>& x, const vector<int>& y, int n, int firstLit) {
    vector<vector<i64>> dp(n, vector<i64>(3, 0));
    if (firstLit == 1) {
        dp[0][1] = x[0];
    } else if (firstLit == 2) {
        dp[0][2] = y[0];
    }

    for (int i = 1; i < n; ++i) {
        dp[i][1] = dp[i-1][2] + x[i];
        dp[i][2] = dp[i-1][1] + y[i];
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
    }
    if (firstLit == 1) {
        dp[n-1][1] = -inf;
    } else if (firstLit == 2) {
        dp[n-1][2] = -inf;
    }
    i64 ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    i64 ans = 0;
    for (int firstLit = 0; firstLit <= 2; ++firstLit) {
        i64 temp = maxScore(x, y, n, firstLit);
        ans = max(ans, temp);        
    }

    cout << "Max score: " << ans << endl;
    return 0;
}

// 
// 5
// 1 3
// 2 4
// 1 5
// 4 1
// 4 2

// Max lamps lit: 4, Max score: 14