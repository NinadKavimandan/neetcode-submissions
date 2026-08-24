class Solution {
public:
    void generate (vector<int>& nums, int start, int subsetLength, vector<int>& subset, vector<vector<int>>& response)
    {
        if (subset.size() == subsetLength)
        {
            response.push_back(subset);
        }
        else
        {
            for (int i=start;i < nums.size();i++)
            {
                subset.push_back(nums[i]);
                generate(nums, i + 1, subsetLength, subset, response);
                subset.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> response;
        vector<int> subset;
        int total = nums.size();
        for (int i=0;i < total+1;i++)
        {
            generate(nums, 0, i, subset, response);
        }

        return response;
    }
};

/*

subsets can be of length 0 to nums.size(). use dfs to generate unique combinations of these sizes

*/