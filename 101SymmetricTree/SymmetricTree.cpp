#include<iostream>
#include<queue>
#include<stack>
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
    queue<TreeNode *> layer;
    bool isSymmetric(TreeNode* root) {
        int n;
        layer.push(root);
        TreeNode *cur;
        while(end())
        {
            n = layer.size();
            stack<int> compare;
            if (n % 2 == 1 && layer.front() != root)
                return false;
            for (int i = 0; i < n; i++)
            {
                cur = layer.front();
                layer.pop();
                if ((i < n / 2) || cur == root)
                {
                    if(cur)
                    {
                        layer.push(cur->left);
                        layer.push(cur->right);
                        compare.push(cur->val);
                    }
                    else
                        compare.push(error_num);
                }
                else
                {
                    if(cur)
                    {
                        layer.push(cur->left);
                        layer.push(cur->right);
                        if (cur->val == compare.top())
                            compare.pop();
                        else
                            return false;
                    }
                    else
                        if (compare.top() == error_num)
                            compare.pop();
                        else
                            return false;
                }
            }
        }
        return true;
    }
private:
    const int error_num = 9999;
    bool end(){
        queue<TreeNode *> pp = layer;
        for (int i = 0; i < layer.size(); i++)
            if (pp.front() != nullptr)
                return true;
            else
                pp.pop();
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
    cout << pp.isSymmetric(root);

    return 0;
}