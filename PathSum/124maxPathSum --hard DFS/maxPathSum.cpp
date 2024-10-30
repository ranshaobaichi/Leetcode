#include<iostream>
using namespace std;

/*
二叉树中的路径被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中至多出现一次。
该路径至少包含一个节点，且不一定经过根节点。

路径和是路径中各节点值的总和。

给你一个二叉树的根节点root，返回其最大路径和。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// @brief 最大路径和
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        path(root);
        return ans;
    }
    int path(TreeNode* root){
        if (root == nullptr)
            return 0;
        int l_val = path(root->left);
        int r_val = path(root->right);

        if(l_val<0) l_val = 0;
        if(r_val<0) r_val = 0;

        //current node be root
        if (root->val + l_val + r_val > ans)
            ans = root->val + l_val + r_val;

        return root->val + max(l_val, r_val);
    }
    int ans = INT_MIN;
};

int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);

    p1->left = p2;
    p1->right = p3;

    Solution pp;
    cout << pp.maxPathSum(p1);

    return 0;
}