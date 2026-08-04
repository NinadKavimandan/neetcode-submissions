class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int targetIndex = -1;
        int start = 0;
        int end = nums.size();

        while (start < end)
        {
            int mid = (start + end)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return targetIndex;
    }
};

/*

maintain a search window, keep on shrinking it by comparing the middle element of the window and the target value.
if window is completely shut out, the value does not exist.

*/