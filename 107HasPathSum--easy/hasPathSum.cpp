#include<iostream>
#include<queue>
using namespace std;

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        queue<pair<TreeNode *, int>> S;
        S.push(make_pair(root,root->val));
        TreeNode *cur = root;
        int sum = 0, pre = 0;
        while (!S.empty())
        {
            int cnt = S.size();
            while (cnt > 0)
            {
                TreeNode *c = S.front().first;
                int temp = S.front().second;
                S.pop();
                if (!c->left && !c->right && c->val == targetSum)
                    return true;
                if(c->left)
                    S.push(make_pair(c->left, temp + c->left->val));
                if(c->right)
                    S.push(make_pair(c->right, temp + c->right->val));
            }
        }
        return false;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(3);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    Solution pp;
    cout << pp.hasPathSum(new TreeNode(-2, nullptr, new TreeNode(-3)), -3);

    return 0;
}