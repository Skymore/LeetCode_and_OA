// normal segment_tree
// zkw segment_tree

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    SegmentTree *left, *right;
    int start, end, sum;

public:
    SegmentTree(int start, int end) : SegmentTree(start, end, 0) { }
    SegmentTree(int start, int end, int sum) : start(start), end(end), sum(sum), left(nullptr), right(nullptr) { }

    // 使用数组nums中的值构建线段树，返回根节点指针
    SegmentTree* build(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr; // 基本的边界条件检查

        // 叶子节点的情况，区间只包含一个元素
        if (start == end) {
            return new SegmentTree(start, end, nums[start]);
        }
        
        // 非叶子节点，递归构建左右子树
        SegmentTree* root = new SegmentTree(start, end);
        int mid = start + (end - start) / 2; // 计算中点，避免溢出
        root->left = build(nums, start, mid); // 构建左子树
        root->right = build(nums, mid + 1, end); // 构建右子树
        root->sum = root->left->sum + root->right->sum; // 更新当前节点的区间和
        return root;
    }

    // 查询区间[left, right]的和，递归实现
    int query(SegmentTree* root, int left, int right) {
        if (root == nullptr) return 0; // 空节点，返回0
        if (left > root->end || right < root->start) return 0; // 查询区间和节点区间不相交，返回0
        if (left <= root->start && right >= root->end) return root->sum; // 查询区间完全覆盖节点区间，直接返回节点的区间和
        
        // 递归查询左右子树，返回区间和
        return query(root->left, left, right) + query(root->right, left, right);
    }

    // 更新操作，将index位置的值更新为val，递归实现
    void update(SegmentTree* root, int index, int val) {
        if (root == nullptr) return; // 空节点直接返回
        if (index < root->start || index > root->end) return; // 更新位置不在当前节点表示的区间内
        
        // 如果当前节点是叶子节点，直接更新值
        if (root->start == root->end && root->start == index) {
            root->sum = val;
            return;
        }
        
        // 否则递归更新左右子树
        update(root->left, index, val);
        update(root->right, index, val);
        
        // 更新完子树后，重新计算当前节点的区间和
        root->sum = root->left->sum + root->right->sum;
    }

};