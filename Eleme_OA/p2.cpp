#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        // 红 紫 黑
        // 红 <= 2
        // 紫 >= 3
        cin >> a >> b >> c;

        if (b + c < 3) {
            cout << -1 << endl;
            continue;
        }

        int minn = 1;

        minn += a / 2;
        if (a % 2 != 0) {
            minn++;
        }

        int maxx = 0;
        maxx += (b / 3);
        b %= 3;
        if (b != 0) {
            if (b + c >= 3) {
                maxx++;
                c -= 3 - b;
            }
        }
        maxx += c + a;
        cout << minn << " " << maxx << endl;
    }
}