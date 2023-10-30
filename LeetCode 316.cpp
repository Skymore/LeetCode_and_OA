class Solution {
public:
    string removeDuplicateLetters(string s) {
        set<char> seen;
        map<char, int> last_pos;
        for (int i = 0; i < s.size(); i++) {
            seen.insert(s[i]);
            last_pos[s[i]] = i;
        }
        string ans;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (i = last_pos[s[i]]) {
                ans += s[i];
            } else {
                if (st.empty()) {
                }
            }
        }
    }
};