class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        n = len(s)
        for i in range(1, n):
            ss = s[i:i+2]
            if ss in s[:::-1]:
                return True
        return False