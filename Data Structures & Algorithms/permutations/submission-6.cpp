class Solution {
public:
    void generate (vector<int>& nums, vector<int>& perm, vector<vector<int>>& response)
    {
        if (perm.size() == nums.size())
        {
            response.push_back(perm);
        }
        else
        {
            for (int i=0;i < nums.size();i++)
            {
                if (find(perm.begin(), perm.end(), nums[i]) == perm.end())
                {
                    perm.push_back(nums[i]);
                    generate(nums, perm, response);
                    perm.pop_back();
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int> perm;
        vector<vector<int>> response;
        generate(nums, perm, response);
        return response;
    }
};

/*

use dfs, select each element at each position

*/