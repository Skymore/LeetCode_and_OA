#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    vector<int> a(n);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
         cin >> a[i];
        a[i] = (a[i] + m - 1) / m;
    }
    

    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());


    for (int i = 0; i < n; i++) {
        cout << b[i].second + 1 << " ";
    }

}