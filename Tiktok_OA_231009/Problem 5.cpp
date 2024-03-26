// Problem Description:
// Given an array arr[] consisting of N integers from the range [1, N]( repetition allowed ),
// the task is to find the minimum common element for each possible subarray length.
// If no such element exists for any particular length of the subarray, then print -1.

#include <iostream>
#include <map>

using namespace std;


// Function to find the minimum common
// element in subarrays of all possible lengths
vector<int> min_comm_ele(vector<int> &v) {
    int n = v.size();
    // maximum distance between every two element
    vector<int> max_dis(n + 1, -1);
    // Stores index of last occurrence of each array element
    map<int, int> last;
    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If array element has not occurred previously
        if (last.find(v[i]) == last.end())
            max_dis[v[i]] = i + 1; // distance is i+1 from the start
        else
            // Compare max_dis[v[i]] with distance from its previous occurrence and store the maximum
            max_dis[v[i]] = max(max_dis[v[i]], i - last[v[i]]);
        last[v[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        // Compare max_dis[i] with distance of its last occurrence from the end
        if (max_dis[i] != -1)
            max_dis[i] = max(max_dis[i], n - last[i]);
    }

    vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        // Check if subarray of length max_dis[i] contains i as one of the common elements
        if (ans[max_dis[i]] == -1)
            ans[max_dis[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        // Find the minimum of all common elements
        if (i > 1 && ans[i - 1] != -1) {
            if (ans[i] == -1)
                ans[i] = ans[i - 1];
            else
                ans[i] = min(ans[i], ans[i - 1]);
        }
    }
    return ans;
}

// Driver Code
int main2() {
    int N = 5;
    vector<int> a = {4, 3, 3, 4, 2};
    auto ans = min_comm_ele(a);
    for (auto i : ans) cout << i << " ";
    return 0;
}