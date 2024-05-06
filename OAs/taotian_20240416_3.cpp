#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <array>

using namespace std;

void dfs(int u, int pa, vector<vector<pair<int, char>>>& g, vector<array<long long, 3>>&dp) {
    const int inf = 0x3f3f3f3f;
    int strong_cnt = 0;
    int strong_idx = -1;
    int min_idx = -1;
    int min_cuts = inf;
    int tot_cuts = 0;

    int sub_size = 0;

    for (auto [v, strong] : g[u]) {
        if (v == pa) continue;
        sub_size++;
        dfs(v, u, g, dp);
        if (strong) {
            strong_cnt++;
            strong_idx = v;
        }
    }
    if (sub_size == 0) {
        dp[u][2] = 0;
        dp[u][1] = 0;
        cout << u << " " << dp[u][1] << " " << dp[u][2] << endl;
        return;
    }

    if (strong_cnt > 1) {
        cout << u << " " << dp[u][1] << " " << dp[u][2] << endl;
        return;
    } else if (strong_cnt == 1) {
        dp[u][2] = dp[strong_idx][1];
        cout << u << " " << dp[u][1] << " " << dp[u][2] << endl;
        return;
    }

    //strong_cnt == 0
    for (auto [v, _] : g[u]) {
        if (v == pa) continue;
        if (dp[v][1] < min_cuts) {
            min_idx = v;
            min_cuts = dp[v][1];
        }
        tot_cuts += dp[v][2];
    }
    dp[u][2] = tot_cuts - dp[min_idx][2] + dp[min_idx][1] + sub_size - 1;
    dp[u][1] = tot_cuts + sub_size;
    cout << "tot_cuts: " << tot_cuts << " min_cuts: " << min_cuts << " min_idx: " << min_idx << endl;
    cout << u << " " << dp[u][1] << " " << dp[u][2] << endl;
    return;
};

int main() {
    int n;
    cin >> n;
    int u, v;
    char ch;
    int inf = 0x3f3f3f3f;

    vector<vector<pair<int, char>>> g(n+1);
    vector<array<long long, 3>> dp(n+1, {inf, inf, inf});
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> ch;
        g[u].push_back(make_pair(v, ch == 'Y'));
        g[v].push_back(make_pair(u, ch == 'Y'));
    }

    dfs(1, -1, g, dp);
    int ans = dp[1][2];

    cout << ans << endl;
    return 0;

}