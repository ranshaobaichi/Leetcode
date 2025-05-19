class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;
    
        Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    
        Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    
        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
    };

class Solution {
    public:
        Node* connect(Node* root) {
            if (root == nullptr) return root;
            Node *start = root;
            while (start)
            {
                Node *next_start = nullptr, *pre = nullptr;
                while (start)
                {
                    if (pre != nullptr)
                    {
                        Node *pre_child = pre->right ? pre->right : (pre->left ? pre->left : nullptr);
                        Node *start_child = start->left ? start->left : (start->right ? start->right : nullptr);
                        if (start_child)
                            pre = start;
                        if (pre_child)
                            pre_child->next = start_child;
                        if (start->left)
                            start->left->next = start->right;
                        if (next_start == nullptr)
                            next_start = start->left ? start->left : start->right;
                    }
                    else
                    {
                        if (start->left)
                            start->left->next = start->right;
                        next_start = start->left ? start->left : start->right;
                        if (start->left || start->right)
                            pre = start;
                    }
                    start = start->next;
                }
                start = next_start;
            }
            return root;
        }
    };

int main()
{
    Solution p;
    Node root(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left->left = new Node(4);
    root.left->right = new Node(5);
    root.left->left->left = new Node(7);
    root.right->right = new Node(6);
    root.right->right->right = new Node(8);
    p.connect(&root);
    return 0;
}