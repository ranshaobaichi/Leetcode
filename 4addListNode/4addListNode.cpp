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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = nullptr, *tail = nullptr;
        int cin = 0;
        while(l1 || l2){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int F = (v1 + v2 + cin) % 10;
            cin = (v1 + v2 + cin) / 10;
            if (l3 == nullptr)
            {                
                l3 = new ListNode(0);
                tail = l3;
            }
            tail->next = new ListNode(F);
            tail = tail->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(cin==1)
            tail->next = new ListNode(1);
        return l3->next;
    }
};

int main(){
    ListNode *l1 = new ListNode(9);
    l1 = new ListNode(9, l1);
    l1 = new ListNode(9, l1);
    l1 = new ListNode(9, l1);


    ListNode *l2 = new ListNode(9);
    l2 = new ListNode(9, l2);

    Solution pp;
    ListNode *l3 = pp.addTwoNumbers(l1, l2);
    while(l3){
        cout << l3->val << ' ';
        l3 = l3->next;
    }
    return 0;
}