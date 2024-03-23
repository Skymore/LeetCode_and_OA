# 一个字符串，输入形式是a(x)b(y)，x代表有连续x个a，怎么读入
# res是这个字符串每个字符，length是每个字符重复的次数
def read_input():
    s = input().strip()
    res = []
    length = []
    i = 0
    while i < len(s):
        if s[i] == '(':
            i += 1
            num = 0
            while s[i] != ')':
                num = num * 10 + int(s[i])
                i += 1
            length.append(num)
        else:
            res.append(s[i])
        i += 1
    return res, length

n, k = map(int, input().split())
res, length = read_input()

ans = 0
i = 0
cur_length = 0
# 统计 26 个字母是否出现过
seen = [0] * 26
while (i < len(res)):
    if seen[ord(res[i]) - ord('a')] == 0:
        seen[ord(res[i]) - ord('a')] = 1
    n_char = sum(seen)
    min_val = n_char * (cur_length + 1)
    max_val = n_char * (cur_length + length[i])

    if max_val < k:
        cur_length += length[i]
        i += 1
    # n_char * (cur_length + m) >= k
    else:
        ans += 1
        m = k // n_char - cur_length
        if k % n_char != 0:
            m += 1
    
        length[i] = length[i] - m
        if (length[i] >= k):
            ans += length[i] // k
            length[i] %= k
        if length[i] == 0:
            i += 1
        
        seen = [0] * 26
        cur_length = 0

if (ans == 0):
    print(-1)
else:
    print(ans)