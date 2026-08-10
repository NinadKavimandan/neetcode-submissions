class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int total = nums.size();
        for (int iter = 1;iter < total;iter++)
        {
            if (nums[iter] == nums[iter-1])
                return nums[iter];
        }

        return -1;
    }
};

/*

lets try to get a working solution first. we can use an unordered set to store everything we have seen, return on the element already present.

*/
