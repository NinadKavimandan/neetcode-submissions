class Solution {
public:
    typedef struct Node {
        int value;
        Node* next;
        Node* prev;
    } Node;

    Node* getNode (int value)
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->value = value;
        temp->next = NULL;
        temp->prev = NULL;

        return temp;
    }

    vector<int> maxSlidingWindow (vector<int>& nums, int k)
    {
        vector<int> response;
        unordered_map<int, Node*> indexNodeMap;
        Node* head;
        Node* end;
        head = getNode(10001);
        end = getNode(-10001);
        head->next = end;
        end->prev = head;

        for (int index=0;index<k;index++)
        {
            Node* temp = getNode(nums[index]);
            indexNodeMap[index] = temp;
            Node* iter = head;

            while (iter->value > temp->value)
            {
                iter = iter->next;
            }

            temp->prev = iter->prev;
            iter->prev->next = temp;
            iter->prev = temp;
            temp->next = iter;
        }

        response.push_back(head->next->value);

        int left = 1;
        int right = k;
        while (right < nums.size())
        {
            indexNodeMap[left - 1]->next->prev = indexNodeMap[left - 1]->prev;
            indexNodeMap[left - 1]->prev->next = indexNodeMap[left - 1]->next;

            Node* temp = getNode(nums[right]);
            indexNodeMap[right] = temp;

            Node* iter = head;

            while (iter->value > temp->value)
            {
                iter = iter->next;
            }

            temp->prev = iter->prev;
            iter->prev->next = temp;
            iter->prev = temp;
            temp->next = iter;
            response.push_back(head->next->value);

            left++;
            right++;
        }

        return response;
    }
};

/*

we need a rolling max kind of thing here.
fetching max from a sequence in general can be efficiently done using a heap, but reconstructing for each window is too much redundant computation.
we can have the elements from the window sorted, and only update the leaving element while sliding ahead, and add new element at its right position from right.
what's a fast way to do that? may be use insertion sort with a map of element to the reference in the sorted list to support quick removals.

why is it correct? we only care about the max in each round, and that only changes if outgoing element was max. this approach ensures the 2nd, 3rd highest elements are always track in case the max is removed while sliding the window, resulting in quick retrieval of the current maximum.

now will it work, let's see.

*/