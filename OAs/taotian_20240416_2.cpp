#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    } else if (n == 2) {
        int maxx = max(a[0], a[1]);
        int minn = min(a[0], a[1]);
        if (minn != maxx) {
            if (maxx == 4 * minn) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        } else {
            cout << 2 << endl;
        }
        return 0;
    }

    int ans = 0;
    for (auto [num, c] : cnt) {
        if (num % 4 == 0) {
            int temp = num / 4;
            if (cnt[temp] > 0) {
                ans = max(ans, c + 1);
            }
        }
        if (num % 2 == 0) {
            int temp = num / 2;
            if (cnt[temp] >= 2) {
                ans = max(ans, c + 2);
            } else if (cnt[temp] >= 1) {
                ans = max(ans, c + 1);
            }
        }
        ans = max(ans, c);
    } 
    cout << ans << endl;
    return 0;
}