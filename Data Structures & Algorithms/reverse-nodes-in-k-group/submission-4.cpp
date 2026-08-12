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
        ListNode dummy;
        ListNode* headGroupReversed = &dummy;
        ListNode* iter = headGroupReversed;
        ListNode* groupStart = head;
        ListNode* groupEnd = head;

        while (groupEnd != nullptr)
        {
            for (int i=0;i < k;i++)
            {
                if (groupEnd == nullptr)
                {
                    iter->next = groupStart;
                    return headGroupReversed->next;
                }

                groupEnd = groupEnd->next;
            }

            ListNode* iterStart = groupStart;
            ListNode* prev = nullptr;
            while (iterStart != groupEnd)
            {
                ListNode* temp = iterStart->next;
                iterStart->next = prev;
                prev = iterStart;
                iterStart = temp;
            }

            iter->next = prev;
            iter = groupStart;
            groupStart = groupEnd;
        }

        iter->next = nullptr;

        return headGroupReversed->next;
    }
};

/*

we can use two pointers k nodes apart, then bring the left pointer towards right while reversing the list. Use a dummy as head, use a pointer iter pointing to the dummy to curate the list. Each time the list is reversed, assign iter->next = fast, if not reversed, iter->next = slow, at the end, if list is reversed, slow->next = nullptr. otherwise fast->next = nullptr (this would be implicit).

*/