/*
 * 题意：
 * 有一个股票，每天的价格是rates[i]，每天的策略是strategies[i]，策略是1表示卖出，策略是0表示不操作，策略是-1表示买入。
 * k是一个偶数，可以把连续k天的策略变成前k/2天都是0，后k/2天都是1，求最大收益。
 */
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &rates, vector<int> &strategies, int k) {
    int n = rates.size();
    int base = 0;
    vector<vector<int>> pre_sum(n + 1, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        base += rates[i] * strategies[i];
        pre_sum[i + 1][0] = pre_sum[i][0] + 0 * rates[i] - strategies[i] * rates[i];
        pre_sum[i + 1][1] = pre_sum[i][1] + 1 * rates[i] - strategies[i] * rates[i];
    }

    int max_delta = 0;
    for (int i = 0; i <= n - k; i++) {
        int d = pre_sum[i + k / 2][0] - pre_sum[i][0]; // [i, i+k/2-1]
        d += pre_sum[i + k][1] - pre_sum[i + k / 2][1]; // [i+k/2, i+k-1]
        if (d > max_delta) {
            max_delta = d;
        }
    }
    return base + max_delta;
}


int main() {
    vector<int> rates = {1000, 2000};
    vector<int> s = {-1, 1};
    cout << solution(rates, s, 2) << endl;
    return 0;
}
