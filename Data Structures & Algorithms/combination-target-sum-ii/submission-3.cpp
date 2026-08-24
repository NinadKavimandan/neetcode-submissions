class Solution {
public:
    void generate (vector<int>& candidates, int start, int curSum, int target, vector<int>& combination, vector<vector<int>>& response)
    {
        if (curSum == target)
        {
            response.push_back(combination);
        }
        else if (curSum < target)
        {
            int prev = INT_MIN;
            for (int i=start;i<candidates.size();i++)
            {
                if (candidates[i] == prev)
                {
                    continue;
                }

                prev = candidates[i];
                if (candidates[i] <= target)
                {
                    combination.push_back(candidates[i]);
                    generate(candidates, i + 1, curSum + candidates[i], target, combination, response);
                    combination.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> response;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        generate(candidates, 0, 0, target, combination, response);

        return response;
    }
};

/*

use dfs to generate combinations, if number is bigger than target, dont pick it as no number is negative.

*/