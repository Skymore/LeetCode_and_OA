#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == p) return true;
        //if (p.empty() || s.empty()) return false;
        int ns = s.size();
        int np = p.size();
        vector<vector<bool> > dp(np+1, vector<bool>(ns+1, 0));
        dp[0][0] = true;
        for (int pi = 1; pi <= np; pi++) {
            if (p[pi-1] == '*') {
                int si = 1;
                while (!dp[pi - 1][si - 1] && si <= ns) {
                    si++;
                }
                dp[pi][si-1] = dp[pi-1][si-1];
                while (si <= ns) {
                    dp[pi][si++] = true;
                }
            } else {
                for (int si = 1; si <= ns; si++) {
                    dp[pi][si] = dp[pi-1][si-1] && s[si-1] == p[pi-1];
                }
            }
        }
        return dp[np][ns];
    }

    vector<string> solver(vector<string> text, vector<string> pat) {
        int n = text.size();
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string s = text[i];
            string p = pat[i];
            bool is_match = isMatch(s, p);
            if (is_match) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            };
        }
        return ans;
    }
};

int main()
{
    vector<string> text = {"code", "coder"};
    vector<string> pat = {"co*d", "co*er"};
    Solution S;
    vector<string> ans = S.solver(text, pat);
    for (auto i: ans) {
        cout << i << endl;
    }
}