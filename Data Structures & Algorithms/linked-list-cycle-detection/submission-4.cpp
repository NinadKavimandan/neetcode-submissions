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
    bool hasCycle(ListNode* head)
    {
        if (head == NULL)
            return false;
        ListNode* fast = head->next;
        ListNode* slow = head;

        do
        {
            if (slow == NULL)
                return false;
            
            if (fast == NULL || fast->next == NULL)
                return false;
            
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        return true;
    }
};

/*

if you encounter NULL, the linked list has no cycle, this is the easy part.
how to detect the cycle? one way could be maintain a list of visited nodes, and if you ever visit a visited node again, there is a cycle. this would run in O(n), with extra space O(n)

*/