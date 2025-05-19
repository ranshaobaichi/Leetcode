/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
*/

#include <iostream>
#include <vector>
#include <queue>
#include "Struct.hpp"
#include "UnitTest.hpp"
using namespace std;

class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists);
};

ListNode *Solution::mergeKLists(vector<ListNode *> &lists)
{
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };
    priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;

    // push into max_heap
    for (int i = 0; i < lists.size(); i++)
        if (lists[i] != nullptr)
            minHeap.push(lists[i]);

    // ListNode head
    ListNode *head = nullptr, *tail = nullptr;
    auto insert_tail = [&head, &tail](ListNode *node)
    {
        if(tail == nullptr)
        {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    };

    while (!minHeap.empty())
    {
        ListNode* tmp = minHeap.top();
        minHeap.pop();
        if (tmp != nullptr)
        {
            ListNode *l = new ListNode(tmp->val);
            insert_tail(l);
            if(tmp->next!= nullptr)
                minHeap.push(tmp->next);
        }
        else
            continue;
    }
    return head;
}

int main()
{
    Solution S;
    UnitTest unitTest;
    unitTest.addTest("test 1", TEST("test 1") { 
        vector<vector<int>> vec = {{1,4,5},{1,3,4},{2,6}};
        vector<int> ans = {1, 1, 2, 3, 4, 4, 5, 6};
        vector<ListNode*> listNodes = createList(vec);
        ASSERT_EQUAL(createList(ans), S.mergeKLists(listNodes));
    });
    return 0;
}