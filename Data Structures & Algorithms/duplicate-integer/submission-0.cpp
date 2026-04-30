class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set<int> seenNumbers;

        for (int num : nums)
        {
            if (seenNumbers.find(num) == seenNumbers.end())
            {
                seenNumbers.insert(num);
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};