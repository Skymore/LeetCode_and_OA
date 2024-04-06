#include <iostream>
#include <vector>

using namespace std;

class ZkwSegmentTree {
private:
    vector<int> tree;
    vector<int> sum;
    int n;
    int M;

    inline void Build(vector<int> &a) {
        // M是非叶子节点的个数
        for (M = 1; M < n - 1; M <<= 1);
        for (int i = M + 1; i <= M + n; i++) 
            tree[i] = a[i - M - 1];
        for (int i = M; i; i--) 
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    inline void update(int x, int v) {
        for (tree[x += M] = v, x >>= 1; x; x >>= 1) 
            tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }


    inline int query(int x) {
        return tree[M + x];
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) ans += tree[l ^ 1];
            if (r & 1) ans += tree[r ^ 1];
        }
        return ans;
    }
};

/*
https://yisous.xyz/posts/orzzkwdl/

https://blog.csdn.net/keshuqi/article/details/52205884?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-52205884-blog-117575178.235%5Ev43%5Epc_blog_bottom_relevance_base8&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-52205884-blog-117575178.235%5Ev43%5Epc_blog_bottom_relevance_base8&utm_relevant_index=13

*/