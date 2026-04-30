class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> numIndexMap;

        for (int index=0;index<nums.size();index++)
        {
            numIndexMap[nums[index]] = index;
        }

        vector<int> response;
        for (int index=0;index<nums.size();index++)
        {
            if (numIndexMap.find(target - nums[index]) != numIndexMap.end())
            {
                if (index == numIndexMap[target - nums[index]])
                {
                    continue;
                }
                response.push_back(index);
                response.push_back(numIndexMap[target - nums[index]]);
                break;
            }
        }

        return response;
    }
};
