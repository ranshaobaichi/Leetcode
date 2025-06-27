#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<int, Node *> map;
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        Node *new_node = new Node(node->val);
        map[node->val] = new_node;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (auto linked : cur->neighbors)
            {
                if (!map.count(linked->val))
                {
                    auto tmp = new Node(linked->val);
                    map[linked->val] = tmp;
                    q.push(linked);
                }
                map[cur->val]->neighbors.push_back(map[linked->val]);
            }
        }
        return new_node;
    }
};