class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> maxHeap;

        for (int stone : stones)
        {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1)
        {
            int heaviest = maxHeap.top();
            maxHeap.pop();
            int secondHeaviest = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(heaviest - secondHeaviest);
        }

        return maxHeap.top();
    }
};

/*

use max heap to pluck out the heaviest 2 stones each time

*/