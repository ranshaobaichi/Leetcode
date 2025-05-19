#include <vector>
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* sortList(ListNode* head) 
        {
            if (head == nullptr || head->next == nullptr) 
                return head;

            ListNode *fast = head->next, *slow = head;
            if (fast != nullptr)
                fast = fast->next;
            while (fast)
            {
                fast = fast->next;
                slow = slow->next;
                if (fast != nullptr)
                    fast = fast->next;
            }
            ListNode *h2 = slow->next;
            slow->next = nullptr;
            return merge(sortList(head), sortList(h2));
        }
        ListNode* merge(ListNode* h1, ListNode* h2)
        {
            ListNode *new_head = nullptr, *new_tail = nullptr;
            while (h1 && h2)
            {
                ListNode *next_node = nullptr;
                if (h1->val <= h2->val)
                {
                    next_node = h1;
                    h1 = h1->next;
                }
                else
                {
                    next_node = h2;
                    h2 = h2->next;
                }

                if (new_head == nullptr)
                {
                    new_head = next_node;
                    new_tail = new_head;
                }
                else
                {
                    new_tail->next = next_node;
                    new_tail = new_tail->next;
                }
            }
            
            while (h1 != nullptr)
            {
                if (new_head == nullptr)
                {
                    new_head = h1;
                    new_tail = new_head;
                }
                else
                {
                    new_tail->next = h1;
                    new_tail = new_tail->next;
                }
                h1 = h1->next;
            }
            
            while (h2 != nullptr)
            {
                if (new_head == nullptr)
                {
                    new_head = h2;
                    new_tail = new_head;
                }
                else
                {
                    new_tail->next = h2;
                    new_tail = new_tail->next;
                }
                h2 = h2->next;
            }

            return new_head;
        }
    };

// 用数组初始化链表的函数
ListNode* createListFromArray(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// 打印链表的函数（用于测试）
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val;
        if (current->next) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

// 释放链表内存的函数
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main()
{
    // 示例使用
    std::vector<int> arr = {-1,5,3,4,0};
    ListNode* head = createListFromArray(arr);
    
    std::cout << "原始链表: ";
    printList(head);
    
    Solution solution;
    ListNode* sortedHead = solution.sortList(head);
    
    std::cout << "排序后链表: ";
    printList(sortedHead);
    
    // 清理内存
    deleteList(sortedHead);
    
    return 0;
}