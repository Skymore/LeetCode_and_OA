#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> manacher(string s) {
    string t{"$#"};
    for (auto c: s) {
        t += c + string("#");
    }
    t += "^";
    vector<int> p(t.size());
    int center = 1, right = 1; // right is the index right to the rightmost palindrome(not included in the palindrome)
    for (int i = 1; i < t.size() - 1; i++) {
        int mirror = 2 * center - i;
        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        } else {
            p[i] = 1;
        }
        while (t[i - p[i]] == t[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    vector<int> ans(s.size());

    // Convert the palindrome radius for the modified string to the lengths in the original string.
    for (int i = 0; i < s.size(); ++i) {
        ans[i] = p[i * 2 + 2] - 1; // p[i*2+1] corresponds to the palindrome radius at s[i].
    }
    return ans;
}

int main() {
    string s = "abacabade";
    vector<int> res = manacher(s);
    int ans = *max_element(res.begin(), res.end());
    cout << "Lengths of longest palindromes centered at each position:" << endl;
    for (auto len : res) {
        cout << len << " ";
    }
    cout << "\nLongest palindrome length: " << ans << endl;
    return 0;
}
