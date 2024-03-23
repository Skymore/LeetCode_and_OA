# tree with n node
# 1. 1 <= n <= 10^5
# 2. 1 <= a[i] <= n

n = int(input()) + 1
graph = [[] for _ in range(n)]
root_prob = [0] * n
prob = [0] * n
depth = [0] * n
degree = [0] * n
M = 19  # 2^19 > 10^5
fa = [[0] * (M + 1) for _ in range(n)]
MODD = 10 ** 9 + 7


def dfs(node):
    for m in range(1, M + 1):
        if (1 << m) <= depth[node]:
            fa[node][m] = fa[fa[node][m - 1]][m - 1]
        else:
            break

    parent = fa[node][0]

    if node == 1:
        prob[node] = 1
        root_prob[node] = 1
    else:
        if parent == 1:
            prob[node] = inv(degree[1])
            root_prob[node] = inv(degree[node])
        else:
            # P(node->root) = P(node->parent) * P(parent->root|不返回node)
            # P(parent->root|不返回node) = P(parent->root) * degree[parent] / (degree[parent] - 1)
            prob[node] = prob[parent] * inv(degree[parent] - 1) % MODD
            p_node_to_parent = inv(degree[node])
            p_parent_to_root_not_return_node = root_prob[parent] * degree[parent] % MODD * inv(
                degree[parent] - 1) % MODD
            root_prob[node] = p_node_to_parent * p_parent_to_root_not_return_node % MODD
    for next in graph[node]:
        if next != parent:
            depth[next] = depth[node] + 1
            fa[next][0] = node
            dfs(next)


def find_lca(x, y):
    if depth[x] < depth[y]:
        x, y = y, x
    diff = depth[x] - depth[y]

    for m in range(M + 1):
        if diff & 1:
            x = fa[x][m]
        diff >>= 1

    if x == y:
        return x

    for m in range(M, -1, -1):
        if fa[x][m] != fa[y][m]:
            x = fa[x][m]
            y = fa[y][m]

    return fa[x][0]


def calc_prob(x, y):
    if x == 1:
        return prob[y]
    if y == 1:
        return root_prob[x]
    if depth[x] > depth[y]:
        # x在下层
        # P(x->root) = P(x->y) * P(y->root|不返回)
        p_y_to_root_not_return_x = root_prob[y] * degree[y] % MODD * inv(degree[y] - 1) % MODD
        p_x_to_y = root_prob[x] * inv(p_y_to_root_not_return_x) % MODD
        return p_x_to_y
    else:
        # P(y->root) = P(y->x) * P(x->root|不返回)
        p_x_to_root_not_return_root = prob[x] * degree[x] % MODD * inv(degree[x] - 1) % MODD
        p_x_to_y = prob[y] * inv(p_x_to_root_not_return_root) % MODD
        return p_x_to_y


# 乘法逆元
# 对于ax ≡ 1 (mod p)，x就是a的逆元
# 逆元存在的条件是a和p互质
# 由费马小定理可知，a^(p-1) ≡ 1 (mod p)
# 所以a^(p-2)就是a的逆元
# pow 函数的第三个参数就是取模的意思
# pow(a, k, p) = a^k % p
# def pow(a, k, p):
#     res = 1
#     while k:
#         if k & 1:
#             res = res * a % p
#         a = a * a % p
#         k >>= 1
#     return res


def inv(a):
    return pow(a, MODD - 2, MODD)


for _ in range(2, n):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
    degree[u] += 1
    degree[v] += 1

dfs(1)
q = int(input())
for _ in range(q):
    s, t = map(int, input().split())
    lc = find_lca(s, t)
    ans = 0
    if s == t:
        ans = 1
    elif lc == s or lc == t:
        ans = calc_prob(s, t)
    else:
        ans = calc_prob(s, lc) * calc_prob(lc, t) % MODD * degree[lc] % MODD * inv(degree[lc] - 1) % MODD

    print(ans)
