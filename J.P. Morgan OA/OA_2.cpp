#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getSubsequenceCount(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<long long> > dp(m + 1, vector<long long>(n + 1, 0));

    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j-1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "HRW", s2 = "HERHRWS";
    cout << getSubsequenceCount(s1, s2) << endl;
    return 0;
}