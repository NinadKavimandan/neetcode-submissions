class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int fast = 0;
        int slow = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        int slow1 = 0;
        while (slow1 != slow)
        {
            slow = nums[slow];
            slow1 = nums[slow1];
        }

        return slow;
    }
};

/*

we know both the lower and upper bounds of n, we can use a fixed size array of booleans to store the seen map, and identify the element already traversed.

or, crazy idea, what if we treat this as linked list, with nums[nums[i]] being the next element for nums[i]? that way, we can use Floyd's cycle detection.

*/
