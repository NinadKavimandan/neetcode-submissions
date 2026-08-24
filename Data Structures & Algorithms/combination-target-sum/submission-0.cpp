class Solution {
public:
    void generate (vector<int>& nums, int start, int curSum, int target, vector<int>& combination, vector<vector<int>>& response)
    {
        if (curSum == target)
        {
            response.push_back(combination);
        }
        else if (curSum < target)
        {
            for (int i=start;i<nums.size();i++)
            {
                if (nums[i] <= target)
                {
                    combination.push_back(nums[i]);
                    generate(nums, i, curSum + nums[i], target, combination, response);
                    combination.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        vector<vector<int>> response;
        vector<int> combination;
        generate(nums, 0, 0, target, combination, response);

        return response;
    }
};

/*

use dfs to generate combinations, if number is bigger than target, dont pick it as no number is negative.

*/