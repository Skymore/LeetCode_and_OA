#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

// 实现自定义的幂运算函数，用于计算 a^k % p

int main() {
    const int MODD = (1e9 + 7);
    int n;
    cin >> n;
    // tree
    vector<vector<int>> tree(n + 1);
    vector<long long> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    vector<long long> depth(n + 1);
    vector<long long> prob_from_root(n + 1);
    vector<long long> prob_to_root(n + 1);
    vector<vector<int>> fa(n + 1, vector<int>(31, 0));

    function<long long(long long, long long, int)> pow =
        [](long long a, long long k, int p) -> long long {
        long long res = 1;
        a %= p;  // 确保 a 在模 p 下
        while (k > 0) {
            if (k & 1) {
                res = res * a % p;
            }
            a = a * a % p;  // 平方
            k >>= 1;
        }
        return res;
    };

    // 计算乘法逆元
    function<long long(long long)> inv = 
    [&](long long a) {
        return pow(a, MODD - 2, MODD);
    };

    function<void(int)> dfs = [&](int node) -> void {
        for (int m = 1; m < 32; m++) {
            if ((1 << m) <= depth[node]) {
                fa[node][m] = fa[fa[node][m - 1]][m - 1];
            } else {
                break;
            }
        }

        int parent = fa[node][0];

        if (node == 1) {
            prob_from_root[node] = 1;
            prob_to_root[node] = 1;
        } else {
            if (parent == 1) {
                prob_from_root[node] = inv(degree[1]);
                prob_to_root[node] = inv(degree[node]);
            } else {
                prob_from_root[node] =
                    prob_from_root[parent] * (degree[parent] - 1) % MODD;
                prob_to_root[node] = prob_to_root[parent] * degree[parent] %
                                     MODD * inv(degree[parent] - 1) % MODD *
                                     inv(degree[node]) % MODD;
            }
        }

        for (int next : tree[node]) {
            if (next != parent) {
                fa[next][0] = node;
                depth[next] = depth[node] + 1;
                dfs(next);
            }
        }
    };

    dfs(1);

    function<int(int, int)> find_lca = [&](int x, int y) -> int {
        if (depth[x] < depth[y])
            return find_lca(y, x);
        // depth[x] >= depth[y]
        long long diff = depth[x] - depth[y];
        for (int i = 0; i < 32; i++) {
            if (diff & 1) {
                x = fa[x][i];
                diff >>= 1;
            }
        }

        if (x == y) {
            return x;
        }

        for (int i = 31; i >= 0; i--) {
            if (fa[x][i] != fa[y][i]) {
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        return fa[x][0];
    };

    function<long long(int, int)> calc_prob = [&](int x, int y) -> long long {
        // 计算从x到y的概率，x为y祖先或者 y为x祖先

        if (x == 1) {
            return prob_from_root[y];
        }
        if (y == 1) {
            return prob_to_root[x];
        }

        if (depth[x] > depth[y]) {
            // y是x的祖先, x在下层
            long long p_y_to_root_not_return_x =
                prob_to_root[y] * degree[y] % MODD * inv(degree[y] - 1) % MODD;
            long long p_x_to_y =
                prob_to_root[x] * inv(p_y_to_root_not_return_x) % MODD;
            return p_x_to_y;
        } else {
            // x是y的祖先, y在下层
            long long p_x_to_root_not_return_root =
                prob_from_root[x] * degree[x] % MODD * inv(degree[x] - 1) % MODD;
            long long p_x_to_y = 
                prob_from_root[y] * inv(p_x_to_root_not_return_root) % MODD;
            return p_x_to_y;
        }
    };

    // query
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        int lca = find_lca(s, t);
        int ans = 0;
        if (s == t) {
            ans = 1;
        } else if (lca == s || lca == t) {
            ans = calc_prob(s, t);
        } else {
            ans = calc_prob(s, lca) * calc_prob(lca, t) % MODD * degree[lca] % MODD * inv(degree[lca] - 1) % MODD;
        }
        cout << ans << endl;
    }
}