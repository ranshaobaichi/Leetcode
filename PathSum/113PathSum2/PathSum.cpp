#include<iostream>
#include<vector>
using namespace std;

/*
给你二叉树的根节点root和一个整数目标和targetSum，
找出所有从根节点到叶子节点路径总和等于给定目标和的路径。

叶子节点是指没有子节点的节点。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> t;
        Path(root, targetSum, t);
        return ans;
    }
    void Path(TreeNode* root, int targetSum, vector<int> temp){
        if (root == nullptr)
            return;
        int new_target = targetSum - root->val;
        temp.push_back(root->val);
        if (new_target == 0 && root->left == nullptr && root->right == nullptr)
            ans.push_back(temp);

        if(root->left)
            Path(root->left, new_target, temp);
        if(root->right)
            Path(root->right, new_target, temp);

    }
    vector<vector<int>> ans;
};