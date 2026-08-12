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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* headGroupReversed = new ListNode();
        ListNode* iter = headGroupReversed;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr)
        {
            for (int i=0;i < k;i++)
            {
                if (fast == nullptr)
                {
                    iter->next = slow;
                    return headGroupReversed->next;
                }

                fast = fast->next;
            }

            ListNode* iterSlow = slow;
            ListNode* prev = nullptr;
            while (iterSlow != fast)
            {
                ListNode* temp = iterSlow->next;
                iterSlow->next = prev;
                prev = iterSlow;
                iterSlow = temp;
            }

            iter->next = prev;
            iter = slow;
            slow = fast;
        }

        iter->next = nullptr;

        return headGroupReversed->next;
    }
};

/*

we can use two pointers k nodes apart, then bring the left pointer towards right while reversing the list. Use a dummy as head, use a pointer iter pointing to the dummy to curate the list. Each time the list is reversed, assign iter->next = fast, if not reversed, iter->next = slow, at the end, if list is reversed, slow->next = nullptr. otherwise fast->next = nullptr (this would be implicit).

*/