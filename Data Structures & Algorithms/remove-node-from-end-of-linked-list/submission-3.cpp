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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
            return nullptr;

        ListNode* iter = head;
        int total = 0;
        while (iter != nullptr)
        {
            total++;
            iter = iter->next;
        }

        int nFromStart = total - n;

        ListNode* prev = nullptr;
        iter = head;
        while (nFromStart != 0)
        {
            prev = iter;
            iter = iter->next;
            nFromStart--;
        }

        ListNode* temp = iter->next;
        iter->next = nullptr;
        if (prev != nullptr)
        {
            prev->next = temp;
        }
        else
        {
            head = temp;
        }

        return head;
    }
};

/*

we can reverse the list once, remove nth element from start, then reverse again
or we can count the total number of nodes in single pass, then compute total - n and remove from start?

in either cases we need to traverse the list at least once, so should be comparable in terms of time complexity, computing total - n is just simpler as we don't need to reverse the list again?

*/