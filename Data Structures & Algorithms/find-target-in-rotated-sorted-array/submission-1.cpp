class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int offset = 0;
        int start = 0;
        int total = nums.size();
        int end = total;

        while (start < end)
        {
            int mid = (start + end)/2;
            if (nums[mid] < nums[0])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        cout<<start<<endl;
        if (start != total)
        {
            offset = start;
        }

        start = 0;
        end = total;
        while (start < end)
        {
            int mid = (start + end)/2;
            if (nums[(mid+offset)%total] == target)
            {
                return (mid+offset)%total;
            }

            if (nums[(mid+offset)%total] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return -1;
    }
};

/*

similar to binary search, with a falling edge.
start the similar way, if mid > target, check mid + 1 and mid - 1, if mid + 1 is smaller than...
actually, scratch that, lets try something simpler first, try to find the offset using binary search, and then apply binary search with (+offset)%n to start and end.

*/