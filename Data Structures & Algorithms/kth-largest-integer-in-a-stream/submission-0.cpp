class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int heapSize;

    KthLargest(int k, vector<int>& nums) 
    {
        heapSize = k;
        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > heapSize)
            {
                minHeap.pop();
            }
        }
    }
    
    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > heapSize)
        {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

/*

use a min heap to maintain max k elements, return top of heap for the kth max element.

*/