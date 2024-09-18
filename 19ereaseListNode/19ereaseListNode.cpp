#include<iostream>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode *> node;
        ListNode *temp = head;
        while(temp){
            if(node.size()==n+1)
                node.pop();
            node.push(temp);
            temp = temp->next;
        }
        ListNode *pre = node.front();
        ListNode *era = pre->next;
        if(node.size()!=n)
        {
            pre->next = era->next;
            delete era;
            return head;
        }
        else
        {
            delete pre;
            return era;
        }
    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    l1 = new ListNode(2, l1);
    // l1 = new ListNode(3, l1);
    // l1 = new ListNode(4, l1);
    // l1 = new ListNode(5, l1);
    // l1 = new ListNode(6, l1);
    // l1 = new ListNode(7, l1);

    Solution pp;
    l1=pp.removeNthFromEnd(l1, 2);

    while(l1){
    cout << l1->val << ' ';
    l1 = l1->next;
    }
    return 0;
}