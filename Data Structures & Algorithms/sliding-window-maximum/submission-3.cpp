class Solution {
public:
    vector<int> maxSlidingWindow (vector<int>& nums, int k)
    {
        vector<int> response;
        deque<int> maxSequence;

        for (int index=0;index<k;index++)
        {
            while (!maxSequence.empty() && nums[maxSequence.front()] < nums[index])
            {
                maxSequence.pop_front();
            }

            maxSequence.push_front(index);
        }

        response.push_back(nums[maxSequence.back()]);

        int left = 1;
        int right = k;
        while (right < nums.size())
        {
            if (nums[left - 1] == nums[maxSequence.back()])
            {
                maxSequence.pop_back();
            }

            while (!maxSequence.empty() && nums[maxSequence.front()] < nums[right])
            {
                maxSequence.pop_front();
            }

            maxSequence.push_front(right);
            
            response.push_back(nums[maxSequence.back()]);

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

okay this works, but not that efficient. what if we use a deque instead, always add from front, remove from back.
if incoming element is greater than back, pop off everything - no may be not. maintain k

*/