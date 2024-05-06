#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }   

    if (n == 2) {
        if (a[0] < a[1] - 1) {
            cout << -1 << endl;
        } else if (a[0] == a[1] - 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }

        if (a[1] < a[0] - 1) {
            cout << -1 << endl;
        } else if (a[1] == a[0] - 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    // 统计最小值和最大值和位置，还有 sum
    long long min_val = a[0];
    long long max_val = a[0];
    long long sum = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
        if (a[i] > max_val) {
            max_val = a[i];
        }
        sum += a[i];
    }

    vector<long long> ans(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] == min_val) continue;
        if (a[i] == max_val) {
            ans[i] = sum;
        } else {
            ans[i] = sum + (max_val - a[i])*2-1;
        }
    }
    long long can_add = 0;

    for (int i = 0; i < n; i++) {
        can_add += max_val - a[i];
    }
    can_add -= max_val - min_val;

    long long ans_min_pos = 0;
    if (min_val + can_add + 1 >= max_val) {
        ans_min_pos = (max_val - min_val) * 2 - 1 + sum;
    } else {
        ans_min_pos = sum + 2 * can_add;
        int cur = min_val + can_add;
        cout << "cur: " << cur << endl;
        cout << "ans_min_pos: " << ans_min_pos << endl;
        while (cur < max_val) {
            cur++;
            ans_min_pos++;
            if (cur == max_val) break;

            for (int i = 0; i < n-1; i++) {
                if (i == 0) max_val++;
                cur++;
                ans_min_pos+=2;
                if (cur == max_val) break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == min_val) {
            cout << ans_min_pos << endl;
        } else {
            cout << ans[i] << endl;
        }
    }

    return 0;
}