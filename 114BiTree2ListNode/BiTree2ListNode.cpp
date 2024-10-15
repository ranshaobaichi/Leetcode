#include<iostream>
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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode *> S;
        S.push(root);
        TreeNode *cur = nullptr, *tail = nullptr;
        while(!S.empty()){
            cur = S.top();
            S.pop();
            if (tail == nullptr)
                tail = cur;
            else
            {
                tail->right = cur;
                tail = tail->right;
            }
            if(cur->right)
                S.push(cur->right);
            if(cur->left)
                S.push(cur->left);
            tail->left = nullptr;
        };
    }
};

int main(){
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);
    TreeNode *p6 = new TreeNode(6);

    p1->left = p2;
    p1->right = p5;
    p2->left = p3;
    p2->right = p4;
    p5->right = p6;

    Solution pp;
    pp.flatten(p1);

    return 0;
}