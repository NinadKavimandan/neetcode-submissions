class Solution {
public:
    void generate (vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& response)
    {
        response.push_back(subset);
        int iter = start;
        while (iter < nums.size())
        {
            subset.push_back(nums[iter]);
            int offset = 1;
            while (iter + offset < nums.size() && nums[iter + offset] == nums[iter])
            {
                offset++;
            }

            generate(nums, iter + 1, subset, response);
            subset.pop_back();
            iter += offset;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> response;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        generate(nums, 0, subset, response);
        return response;
    }
};

/*

sort and use dfs to generate combinations

*/