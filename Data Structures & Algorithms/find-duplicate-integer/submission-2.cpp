class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        unordered_set<int> seen;
        int total = nums.size();
        for (int iter = 0;iter < total;iter++)
        {
            if (seen.find(nums[iter]) != seen.end())
            {
                return nums[iter];
            }

            seen.insert(nums[iter]);
        }

        return -1;
    }
};

/*

lets try to get a working solution first. we can use an unordered set to store everything we have seen, return on the element already present.

*/
