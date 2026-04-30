class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> numSet;
        int maxLength = 0;
        int curLength = 0;
        for (int index=0;index<nums.size();index++)
        {
            numSet.insert(nums[index]);
        }

        for (int iter=0;iter<nums.size();iter++)
        {
            if (numSet.find(nums[iter] - 1) != numSet.end())
            {
                continue;
            }

            int num = nums[iter];
            while (numSet.find(num++) != numSet.end())
            {
                curLength++;
            }

            if (curLength > maxLength)
            {
                maxLength = curLength;
            }
            curLength = 0;
        }

        if (curLength > maxLength)
        {
            maxLength = curLength;
        }

        return maxLength;
    }
};

/*

just maintain the continuously increasing sequence length, if next element is not n+1, restart it.
okay I got it wrong, completely, its not what I thought it is, and I am embarassed for presenting such a solution.
yeah its actually easy, you just need it in linear time which makes it harder. But there are constraints, so can use an array of 1000 elements, all bool may be, and just see longest growing subsequence.

update - embarassed yet again, the range is basically INT_MIN to INT_MAX;

okay now, we can maintain list of all elements first, and a map for element against the index
*/