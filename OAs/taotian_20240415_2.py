def max_score(x, y, n, first_lit):
    # 初始化 dp 数组，每个元素是一个长度为3的列表，存储不点亮、蓝色和黄色的状态
    dp = [[(0, 0)] * 3 for _ in range(n)]
    
    # 根据第一盏灯的状态初始化
    if first_lit == 1:  # 第一盏灯点亮为蓝色
        dp[0][1] = (1, x[0])
    elif first_lit == 2:  # 第一盏灯点亮为黄色
        dp[0][2] = (1, y[0])

    # 动态规划填表
    for i in range(1, n):
        dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2])
        dp[i][1] = (dp[i-1][0][0] + 1, dp[i-1][0][1] + x[i])
        dp[i][2] = (dp[i-1][0][0] + 1, dp[i-1][0][1] + y[i])
        
        dp[i][1] = max(dp[i][1], (dp[i-1][2][0] + 1, dp[i-1][2][1] + x[i]))
        dp[i][2] = max(dp[i][2], (dp[i-1][1][0] + 1, dp[i-1][1][1] + y[i]))

    # 根据第一盏灯的状态，选择最后一盏灯的合适状态
    if first_lit == 1:
        return max(dp[n-1][0], dp[n-1][2])
    elif first_lit == 2:
        return max(dp[n-1][0], dp[n-1][1])
    else:
        return max(dp[n-1][0], dp[n-1][1], dp[n-1][2])

def main():

    n = int(input())
    x, y = [], []
    for _ in range(n):
        a, b = map(int, input().split())
        x.append(a)
        y.append(b)

    best = (0, 0)
    # 分别计算三种情况
    for first_lit in range(3):
        result = max_score(x, y, n, first_lit)
        if result[0] > best[0] or (result[0] == best[0] and result[1] > best[1]):
            best = result

    print(f"Max lamps lit: {best[0]}, Max score: {best[1]}")

if __name__ == "__main__":
    main()
