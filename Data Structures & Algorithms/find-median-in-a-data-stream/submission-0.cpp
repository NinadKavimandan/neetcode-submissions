class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int count = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num)
    {
        if (maxHeap.empty())
        {
            maxHeap.push(num);
        }
        else
        {
            if (num > maxHeap.top())
            {
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        count++;
    }
    
    double findMedian()
    {
        if (count%2 != 0)
        {
            return (double)maxHeap.top();
        }

        return (maxHeap.top() + minHeap.top())/2.0;
    }
};

/*

maintain two heaps, of nearly same size, one max, one min, allow max heap to have + 1 extra elements than min heap, so its top becomes the median on odd number of elements in the stream, while average out both the tops if its even. Balance out the max and min heaps to not differ in size during addNum.

*/