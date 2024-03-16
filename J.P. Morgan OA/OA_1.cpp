#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinServers(int expected_load, vector<int> server) {
    sort(server.begin(), server.end(), greater<int>());
    int n = server.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (expected_load - server[i] >= 0) {
            expected_load -= server[i];
            ans++;
        }
    }
    return expected_load == 0 ? ans : -1;
}

int main() {
    std::vector<int> server{1, 1, 2, 4, 4};
    int expected_load = 10;
    cout << getMinServers(expected_load, server) << endl;
    return 0;
}