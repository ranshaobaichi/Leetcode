#include<iostream>
using namespace std;

/*给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        if(k==0)
            return head;
        ListNode *cur = head;
        int length = 1;
        while(cur->next)
        {
            length++;
            cur = cur->next;
        }
        cur->next = head;
        for (int i = 0; i < length - (k % length) - 1; i++)
            head = head->next;
        ListNode *temp = head;
        head = head->next;
        temp->next = nullptr;
        return head;
    }
};

int main(){
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    // ListNode *p3 = new ListNode(3);
    // ListNode *p4 = new ListNode(4);
    // ListNode *p5 = new ListNode(5);

    p1->next = p2;
    // p2->next = p3;
    // p3->next = p4;
    // p4->next = p5;

    Solution pp;

    ListNode *c = pp.rotateRight(p1, 1);

    while (c)
    {
        cout << c->val;
        c = c->next;
    }
    
    return 0;
}