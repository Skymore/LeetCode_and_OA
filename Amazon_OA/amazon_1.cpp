#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sLen = s.length(), pLen = p.length();
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;

        while (sIdx < sLen) {
            if (pIdx < pLen && p[pIdx] == s[sIdx]) {
                ++sIdx;
                ++pIdx;
            }
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                sTmpIdx = sIdx;
                ++pIdx;
            }
            else if (starIdx == -1) {
                return false;
            }
            else {
                pIdx = starIdx + 1;
                sIdx = sTmpIdx + 1;
                sTmpIdx = sIdx;
            }
        }

        for (int i = pIdx; i < pLen; i++) {
            if (p[i] != '*') {
                return false;
            }
        }
        return true;
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