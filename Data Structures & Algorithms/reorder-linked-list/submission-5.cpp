/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head)
    {
        ListNode* iter = head;
        ListNode* split = head;

        while (iter != nullptr && iter->next != nullptr)
        {
            split = split->next;
            iter = iter->next->next;
        }
        
        ListNode* rev = split->next;
        ListNode* prev = nullptr;
        split->next = nullptr;

        while (rev != nullptr)
        {
            ListNode* temp = rev->next;
            rev->next = prev;
            prev = rev;
            rev = temp;
        }

        rev = prev;
        iter = head;
        while (iter != nullptr && rev != nullptr)
        {
            ListNode* temp = iter->next;
            ListNode* tempRev = rev->next;
            iter->next = rev;
            rev->next = temp;
            iter = temp;
            rev = tempRev;
        }
    }
};

/*

the best way to solve this is to have context of elements from both ends at the same time.
a simple solution could be to use a stack, traverse once, then while traversing, add top of the stack, then add the regular element, and continue the same till stack is empty, but then how would you invalidate the entry already added to the stack?

lets try splitting the list into two, half forward, half reversed.

1 2 3 4 5 6 7

4 5 6 7
4->prev
5->4->prev
6->5->4->prev
7->6->5->4->prev
*/