#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    double f = static_cast<double>(n);
    double ans = (1 / f) * (1 / (f - 1)) * 2;
    ans += 0.00000000005;
    printf("%.10f\n", ans);
}