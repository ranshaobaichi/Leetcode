#include<iostream>
using namespace std;

/*给你一个链表，两两交换其中相邻的节点，
并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head);
};

ListNode *Solution::swapPairs(ListNode *head)
{
    if (head && head->next)
    {
        ListNode *fir = head, *sec = head->next;
        fir->next = swapPairs(sec->next);
        sec->next = fir;
        return sec;
    }
    else
        return head;
}

int main(){
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    Solution pp;

    ListNode *c = pp.swapPairs(p1);

    while (c)
    {
        cout << c->val;
        c = c->next;
    }
    
    return 0;
}