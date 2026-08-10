/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node* newHead = new Node(head->val);

        Node* iter = head;
        Node* iterNew = newHead;

        while (iter != nullptr)
        {
            Node* tempNext = iter->next;
            if (tempNext == nullptr)
            {
                iterNew->next = nullptr;
            }
            else
            {
                iterNew->next = new Node(tempNext->val);
            }

            iter->next = iterNew;
            iterNew->random = iter->random;

            iter = tempNext;
            iterNew = iterNew->next;
        }

        iterNew = newHead;

        while (iterNew != nullptr)
        {
            if (iterNew->random != nullptr)
            {
                iterNew->random = iterNew->random->next;
            }

            iterNew = iterNew->next;
        }

        return newHead;
    }
};

/*

start with head, for each next, create new node and assign to next in the new list, and proceed with both the lists to next. same goes for random. use a map to store old to new list nodes to ensure the integrity of next and random ptrs pointing to the same node.

to make it use constant space, what if in the first pass we make each pointer point to their own new selves for next pointer, and for the random nodes in new list, we assign them to their older selves?

*/