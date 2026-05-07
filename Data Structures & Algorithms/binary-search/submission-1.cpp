class Solution {
public:
    int search(vector<int>& nums, int target) {
        int response = -1;

        int left = 0;
        int right = nums.size();
        int mid = (left + right)/2;
        while (left < right)
        {
            if (nums[mid] > target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                response = mid;
                break;
            }

            mid = (left + right)/2;
        }

        return response;
    }
};
