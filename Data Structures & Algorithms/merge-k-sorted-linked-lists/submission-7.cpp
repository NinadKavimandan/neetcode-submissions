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
        int globalMin = INT_MAX;
        int globalMax = INT_MIN;
        unordered_map<int, int> nodeFreqMap;

        for (int i = 0;i < k;i++)
        {
            ListNode* temp = lists[i];
            while (temp != nullptr)
            {
                nodeFreqMap[temp->val]++;
                globalMin = min(globalMin, temp->val);
                globalMax = max(globalMax, temp->val);
                temp = temp->next;
            }
        }

        for (int i = globalMin;i <= globalMax;i++)
        {
            int freq = nodeFreqMap[i];

            for (int j = 0;j < freq;j++)
            {
                iter->next = new ListNode(i);
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