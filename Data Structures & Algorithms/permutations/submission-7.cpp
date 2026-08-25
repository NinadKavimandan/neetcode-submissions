class Solution {
public:
    void generate (vector<int>& nums, vector<bool>& used, vector<int>& perm, vector<vector<int>>& response)
    {
        if (perm.size() == nums.size())
        {
            response.push_back(perm);
        }
        else
        {
            for (int i=0;i < nums.size();i++)
            {
                if (!used[i])
                {
                    perm.push_back(nums[i]);
                    used[i] = true;
                    generate(nums, used, perm, response);
                    used[i] = false;
                    perm.pop_back();
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int> perm;
        vector<bool> used(nums.size(), false);
        vector<vector<int>> response;
        generate(nums, used, perm, response);
        return response;
    }
};

/*

use dfs, select each element at each position

*/