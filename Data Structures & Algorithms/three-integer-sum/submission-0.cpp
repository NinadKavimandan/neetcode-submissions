class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> response;
        for (int index=0;index<nums.size();index++)
        {
            if (index > 0 && nums[index] == nums[index - 1])
                continue;
            int start = index + 1;
            int end = nums.size() - 1;
            int target = -1*nums[index];

            while (start < end)
            {
                int curSum = nums[start] + nums[end];
                if (curSum < target)
                {
                    start++;
                }
                else if (curSum > target)
                {
                    end--;
                }
                else
                {
                    response.push_back({nums[index], nums[start], nums[end]});

                    int curStart = nums[start];
                    while (start < end && curStart == nums[start])
                        start++;
                    
                    int curEnd = nums[end];
                    while (start < end && curEnd == nums[end])
                        end--;
                }
            }
        }

        return response;
    }
};

/*

start with left most element, say x, look for the two elements in the right sub-array that adds up to -x.
process of findings the two elements leading to -x can be done in a single pass if we store elements against their indices, or if we just sort the array beforehand, we need to store anything and just use two pointer method.

*/