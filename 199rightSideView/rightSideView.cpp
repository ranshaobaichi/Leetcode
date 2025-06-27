#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>();
        queue<TreeNode *> Q;
        vector<int> ans;
        Q.push(root);
        while (!Q.empty())
        {
            int sz = Q.size();
            for (int i = 0; i < sz; i++)
            {
                auto node = Q.front();
                if (i == sz - 1)
                    ans.push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                Q.pop();
            }
        }
        return ans;
    }
};