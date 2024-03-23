def solve(s):
    ans = 0
    length = 1

    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            length += 1
        else:
            if length >= 2:
                ans += length - 1
            length = 1

    if length >= 2:
        ans += length - 1

    return ans

n = int(input())
s = input()
print(solve(s))