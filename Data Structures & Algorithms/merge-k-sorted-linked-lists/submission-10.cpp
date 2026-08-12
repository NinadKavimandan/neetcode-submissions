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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* head = new ListNode();
        ListNode* iter = head;
        int k = lists.size();
        map<int, vector<ListNode*>> nodeFreqMap;

        for (int i = 0;i < k;i++)
        {
            ListNode* temp = lists[i];
            while (temp != nullptr)
            {
                nodeFreqMap[temp->val].push_back(temp);
                temp = temp->next;
            }
        }

        for (auto& entry : nodeFreqMap)
        {
            for (ListNode* temp : entry.second)
            {
                iter->next = temp;
                iter = iter->next;
            }
        }

        iter->next = nullptr;

        return head->next;
    }
};

/*

iterate over all k lists one from each at a time, use min heap to pull out the minimum. Repeat untill all lists are traversed and heap is empty.
times out, rightfully so

what if we maintain a map of all unique integers present, compute only minimum and maximum, and just reconstruct the merged list based on a frequency map?

*/