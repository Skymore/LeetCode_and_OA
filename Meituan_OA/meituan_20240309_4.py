# meituan_2024.3.9_4.py

n, k = map(int, input().split())
a2 = [0] * n
a5 = [0] * n
a = list(map(int, input().split))
for i in range(n):
    while a[i] % 2 == 0:
        a[i] //= 2
        a2[i] += 1
    while a[i] % 5 == 0:
        a[i] //= 5
        a5[i] += 1

cnt2 = sum(a2)
cnt5 = sum(a5)
left = 0
res = 0
for right in range(n):
    cnt2 -= a2[right]
    cnt5 -= a5[right]
    while left <= right and min(cnt2, cnt5) < k:
        cnt2 += a2[left]
        cnt5 += a5[left]
        left += 1
    res += right - left + 1

print(res)
