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
        ListNode start(0, head);

        ListNode* right = &start;
        ListNode* left = &start;

        for(int i=0;i<n;i++)
        {
            right = right->next;
        }

        while (right->next != nullptr)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return start.next;
    }
};

/*

use two pointers n nodes apart. take the pointer on the right towards end and you get the nth element on the ptr on left.

*/