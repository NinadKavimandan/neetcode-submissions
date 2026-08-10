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
    Node* getNode(unordered_map<Node*, Node*>& nodeMap, Node* oldNode)
    {
        if (oldNode == nullptr)
        {
            return nullptr;
        }
        if (nodeMap.find(oldNode) == nodeMap.end())
        {
            nodeMap[oldNode] = new Node(oldNode->val);
        }

        return nodeMap[oldNode];
    }

    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node* newHead = new Node(head->val);
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[head] = newHead;

        Node* iter = head;
        Node* iterNew = newHead;

        while (iter != nullptr)
        {
            Node* tempNext = iter->next;
            iterNew->next = getNode(nodeMap, tempNext);

            Node* tempRandom = iter->random;
            iterNew->random = getNode(nodeMap, tempRandom);

            iter = iter->next;
            iterNew = iterNew->next;
        }

        return newHead;
    }
};

/*

start with head, for each next, create new node and assign to next in the new list, and proceed with both the lists to next. same goes for random. use a map to store old to new list nodes to ensure the integrity of next and random ptrs pointing to the same node.

*/