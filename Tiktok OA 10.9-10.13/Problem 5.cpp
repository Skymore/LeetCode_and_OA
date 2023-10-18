#include <iostream>
#include <map>

using namespace std;

// Function to find maximum distance
// between every two element
void max_distance(int a[], int temp[], int n) {
    // Stores index of last occurrence
    // of each array element
    map<int, int> mp;

    // Initialize temp[] with -1
    for (int i = 1; i <= n; i++) {
        temp[i] = -1;
    }

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If array element has
        // not occurred previously
        if (mp.find(a[i]) == mp.end())
            // Update index in temp
            temp[a[i]] = i + 1;
            // Otherwise
        else
            // Compare temp[a[i]] with distance
            // from its previous occurrence and
            // store the maximum
            temp[a[i]] = max(temp[a[i]], i - mp[a[i]]);
        mp[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        // Compare temp[i] with distance
        // of its last occurrence from the end
        // of the array and store the maximum
        if (temp[i] != -1)
            temp[i] = max(temp[i], n - mp[i]);
    }
}

// Function to find the minimum common
// element in subarrays of all possible lengths
void min_comm_ele(int a[], int ans[],
                  int temp[], int n) {
    // Function call to find the maximum
    // distance between every pair of repetition
    max_distance(a, temp, n);

    // Initialize ans[] to -1
    for (int i = 1; i <= n; i++) {
        ans[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        // Check if subarray of length
        // temp[i] contains i as one
        // of the common elements
        if (ans[temp[i]] == -1)
            ans[temp[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        // Find the minimum of all
        // common elements
        if (i > 1 && ans[i - 1] != -1) {
            if (ans[i] == -1)
                ans[i] = ans[i - 1];
            else
                ans[i] = min(ans[i],
                             ans[i - 1]);
        }
        cout << ans[i] << " ";
    }
}

// Driver Code
int main2() {
    int N = 5;
    int a[] = {4, 3, 3, 4, 2};
    int temp[100], ans[100];
    min_comm_ele(a, ans, temp, N);

    return 0;
}