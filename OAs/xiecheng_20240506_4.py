def solve(tree, value):
    n = len(tree)
    dp_down = [[0, 0, 0] for _ in range(n)]
    dp_up = [[0, 0, 0] for _ in range(n)]
    
    def dfs_down(node, parent):
        dp_down[node][value[node] % 3] = 1
        for child in tree[node]:
            if child != parent:
                dfs_down(child, node)
                for j in range(3):
                    new_index = (value[node] % 3 + j) % 3
                    dp_down[node][new_index] += dp_down[child][j]
    
    def dfs_up(node, parent):
        if parent is not None:
            # 初始化当前节点的 dp_up
            fa = [0] * 3
            dp_up[node] = [0] * 3

            # 计算父节点的 dp_down 对当前节点的影响，除去当前节点的直接贡献
            for i in range(3):
                # 根据父节点的值调整索引，以正确地处理模3的影响
                adjusted_index = (i - value[parent] % 3 + 3) % 3
                fa[i] = dp_up[parent][i] + dp_down[parent][i] - dp_down[node][adjusted_index]

            # 考虑当前节点的值对路径和的影响
            for i in range(3):
                # 根据当前节点的值调整索引，以正确地处理模3的影响
                adjusted_index = (i - value[node] % 3 + 3) % 3
                dp_up[node][i] = fa[adjusted_index]

        for child in tree[node]:
            if child != parent:
                dfs_up(child, node)

    
    dfs_down(0, None)
    dfs_up(0, None)

    # 合并
    dp = [0] * n
    for i in range(n):
        dp[i] = dp_down[i][0] + dp_up[i][0]

    return dp, dp_down, dp_up

# Example usage
n = int(input())
value = list(map(int, input().split()))
tree = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    tree[u-1].append(v-1)
    tree[v-1].append(u-1)

print(tree)

dp, dp_down, dp_up= solve(tree, value)
print(dp_down)
print(dp_up)
print(dp)

# Input
# 3
# 1 2 3
# 1 2
# 2 3
# Output
# [2, 0, 2]