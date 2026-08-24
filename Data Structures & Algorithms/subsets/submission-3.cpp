class Solution {
public:
    void generate (vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& response)
    {
        response.push_back(subset);
        if (start == nums.size())
        {
            return;
        }

        for (int i=start;i < nums.size();i++)
        {
            subset.push_back(nums[i]);
            generate(nums, i + 1, subset, response);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> response;
        vector<int> subset;
        int total = nums.size();
        generate(nums, 0, subset, response);

        return response;
    }
};

/*

subsets can be of length 0 to nums.size(). use dfs to generate unique combinations of these sizes

*/