class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;

        if (k > nums.size() - k + 1)
        {
            k = nums.size() - k + 1;

            for (int num : nums)
            {
                maxHeap.push(num);

                if (maxHeap.size() > k)
                {
                    maxHeap.pop();
                }
            }

            return maxHeap.top();
        }

        for (int num : nums)
        {
            minHeap.push(num);

            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

/*

use a min heap to maintain top k elements, return top at the end, that would be k largest element.

*/