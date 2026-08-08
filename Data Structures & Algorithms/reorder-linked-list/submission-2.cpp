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
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;
        stack<ListNode*> nodeStack;
        ListNode* iter = head;
        while (iter != nullptr)
        {
            nodeStack.push(iter);
            iter = iter->next;
        }

        iter = head;

        while (!nodeStack.empty())
        {
            ListNode* temp = iter->next;
            iter->next = nodeStack.top();
            iter->next->next = temp;
            cout<<iter->val<<" "<<nodeStack.top()->val<<" "<<temp->val<<endl;
            nodeStack.pop();
            iter = temp;

            if (temp == nodeStack.top())
            {
                temp->next = nullptr;
                break;
            }

            if (temp->next == nodeStack.top())
            {
                nodeStack.top()->next = nullptr;
                break;
            }
        }
    }
};

/*

the best way to solve this is to have context of elements from both ends at the same time.
a simple solution could be to use a stack, traverse once, then while traversing, add top of the stack, then add the regular element, and continue the same till stack is empty, but then how would you invalidate the entry already added to the stack?

1 2 3 4 5

1 5 2 3 4

1 5 2 4 3 -> temp == stack top

1 2 3 4 5 6

1 6 2 3 4 5

1 6 2 5 3 4

*/