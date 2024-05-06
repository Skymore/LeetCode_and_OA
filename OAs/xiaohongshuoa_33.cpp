#include<bits/stdc++.h>

using namespace std;

const int N = 1E5 + 100;
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

    if (n == 2) {
        for (int i = 0; i < n; i++) {
            if (a[i] == maxx) cout << a[i] << endl;
            else puts("-1");
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        long long l = maxx, r = 1e13;
        while (ll < rr) {
            long long mid = (l + r) >> 1ll;
            if (check(a[i], mid)) {
                rr = mid;
            } else {
                ll = mid + 1;
            }
        }
        long long ans = sum + l - a[i] + max(0ll, l-a[i]-1);
        cout << ans << endl;
    }
    return 0;
}