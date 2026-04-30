class Solution {
public:
    typedef struct Node
    {
        int value;
        int count;
    } Node;

    struct NodeComparator
    {
        bool operator()(Node* a, Node* b)
        {
            return a->count > b->count;
        }
    };

    Node* getNode(int value)
    {
        Node* temp = (Node*) malloc(sizeof(Node));
        temp->value = value;
        temp->count = 1;

        return temp;
    }

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        priority_queue<Node*, vector<Node*>, NodeComparator> minHeap;
        unordered_map<int, Node*> numNodeMap;
        for (int num : nums)
        {

            if (numNodeMap.find(num) == numNodeMap.end())
            {
                numNodeMap[num] = getNode(num);
            }
            else
            {
                numNodeMap[num]->count++;
            }
        }

        for (auto& entry : numNodeMap)
        {
            minHeap.push(entry.second);
        }

        while (minHeap.size() != k)
        {
            minHeap.pop();
        }

        vector<int> response;

        while (!minHeap.empty())
        {
            response.push_back(minHeap.top()->value);
            minHeap.pop();
        }

        return response;
    }
};


/*

return top k most frequent elements.
now then, the most famous method to solve this is by using a min heap, use a tuple, element against the count. While returning the response, first eliminate all elements till heap size becomes k, then return remaining elements as the response.

although my heap skills a bit hazy, but lets see

*/