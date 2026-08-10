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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        ListNode* answer = new ListNode(0);
        ListNode* ansIter = answer;
        while (iter1 != nullptr && iter2 != nullptr)
        {
            int sum = iter1->val + iter2->val + carry;
            carry = sum/10;

            ansIter->next = new ListNode(sum%10);
            ansIter = ansIter->next;
            iter1 = iter1->next;
            iter2 = iter2->next;
        }

        while (iter1 != nullptr)
        {
            int sum = carry + iter1->val;
            carry = sum/10;
            ansIter->next = new ListNode(sum%10);
            ansIter = ansIter->next;
            iter1 = iter1->next;
        }

        while (iter2 != nullptr)
        {
            int sum = carry + iter2->val;
            carry = sum/10;
            ansIter->next = new ListNode(sum%10);
            ansIter = ansIter->next;
            iter2 = iter2->next;
        }

        if (carry > 0)
        {
            ansIter->next = new ListNode(carry);
            ansIter = ansIter->next;
        }

        return answer->next;
    }
};

/*

two iterators, one for each list, move from lsb to msb. Add both values and maintain a carry throughout, if carry is non-zero at msb, add additional node to the answer

*/