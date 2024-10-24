#include<iostream>
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
    ListNode *tail;
    ListNode *reverseList(ListNode *head)
    {
        reverse(head);
        return tail;
    }
    ListNode* reverse(ListNode *head)
    {
        if (!head || !head->next)
        {
            tail = head;
            return head;
        }
        reverse(head->next)->next = head;
        head->next = nullptr;
        return head;    
    }
};

int main(){
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Solution pp;
    ListNode *cur = pp.reverseList(p1);

    while(cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }

    return 0;
}