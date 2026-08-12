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
    struct ListNodeComparator
    {
        bool operator()(const ListNode* a, const ListNode* b)
        {
            return a->val > b->val;
        };
    };

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> nodeHeap;
        ListNode* head = new ListNode();
        ListNode* iter = head;
        int k = lists.size();

        for (int i = 0;i < k;i++)
        {
            if (lists[i] != nullptr)
            {
                nodeHeap.push(lists[i]);
            }
        }

        while (!nodeHeap.empty())
        {
            ListNode* temp = nodeHeap.top();
            iter->next = temp;
            iter = iter->next;
            nodeHeap.pop();
            if (temp->next != nullptr)
            {
                nodeHeap.push(temp->next);
            }
        }

        iter->next = nullptr;

        return head->next;
    }
};

/*

iterate over all k lists one from each at a time, use min heap to pull out the minimum. Repeat untill all lists are traversed and heap is empty.

*/