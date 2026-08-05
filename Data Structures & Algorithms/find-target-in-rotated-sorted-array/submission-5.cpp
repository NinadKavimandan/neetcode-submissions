class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int start = 0;
        int total = nums.size();
        int end = total;

        while (start < end)
        {
            int mid = (start + end)/2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[start] < nums[mid])
            {
                if (nums[mid] < target || nums[start] > target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid;
                }
            }
            else
            {
                if (nums[mid] > target || nums[end - 1] < target)
                {
                    end = mid;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }

        return -1;
    }
};

/*

similar to binary search, with a falling edge.
start the similar way, if mid > target, check mid + 1 and mid - 1, if mid + 1 is smaller than...
actually, scratch that, lets try something simpler first, try to find the offset using binary search, and then apply binary search with (+offset)%n to start and end.

managed to get it work with two pass binary search, lets see if we can reduce this to a single pass.
instead of standard comparison with just mid, we can use both start and end as well to determine which window to move forward with next

*/