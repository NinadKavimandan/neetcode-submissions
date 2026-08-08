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
        ListNode* iter = head;
        unordered_map<ListNode*, bool> visited;

        while (iter != NULL)
        {
            if (visited[iter])
            {
                return true;
            }

            visited[iter] = true;
            iter = iter->next;
        }

        return false;
    }
};

/*

if you encounter NULL, the linked list has no cycle, this is the easy part.
how to detect the cycle? one way could be maintain a list of visited nodes, and if you ever visit a visited node again, there is a cycle. this would run in O(n), with extra space O(n)

*/