#include<bits/stdc++.h>

using namespace std;

const int N = 1E5 + 5;
int n, a[N];
long long sum = 0;
bool check(long long ai, long long x) {
    return x - ai <= x * (n-1) - (sum-ai)+1;
}

int main() {
    cin >> n;
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        maxx = max(maxx, a[i]);
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

    for (int i = 0; i < n; i++) {
        long long ll = maxx, rr = 1e12;
        while (ll < rr) {
            long long mid = (l + r) >> 1;
            if (check(a[i], mid)) {
                rr = mid;
            } else {
                ll = mid + 1;
            }
        }
        long long ans = sum + ll - a[i] + max(0ll, ll-a[i]-1);
        cout << ans << endl;
    }
    return 0;
}