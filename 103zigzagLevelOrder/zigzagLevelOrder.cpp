#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nums;
        vector<int> temp;
        stack<TreeNode *> cur;
        TreeNode *p;
        bool left = true;
        if(root)
            cur.push(root);
        else
            return vector<vector<int>>();
        while(!cur.empty())
        {
            stack<TreeNode *> nex;
            temp.clear();
            while (!cur.empty())
            {
                p = cur.top();
                cur.pop();
                temp.push_back(p->val);
                put(p, left, nex);
            }
            nums.push_back(temp);
            cur = nex;
            left = !left;
        }
        return nums;
    }
private:
    void put(TreeNode *node, bool left, stack<TreeNode *> &S)
    {
        if (!(node->left || node->right))
            return;
        if(!node->left)
            S.push(node->right);
        else if(!node->right)
            S.push(node->left);
        else
            if(left)
            {
                S.push(node->left);
                S.push(node->right);
            }
            else
            {
                S.push(node->right);
                S.push(node->left);
            }
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    TreeNode *p1 = new TreeNode(9);
    TreeNode *p2 = new TreeNode(20);
    TreeNode *p3 = new TreeNode(15);
    TreeNode *p4 = new TreeNode(7);

    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;

    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    a->left = b;

    Solution qq;
    vector<vector<int>> ans = qq.zigzagLevelOrder(a);
    for_each(ans.begin(), ans.end(), [](vector<int> &in)
    { 
        for_each(in.begin(), in.end(), [](int a)
        {
            cout << a << ' ';
        });
        cout << endl;
    });
    return 0;
}