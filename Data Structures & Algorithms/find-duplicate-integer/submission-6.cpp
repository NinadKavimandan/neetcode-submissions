class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        vector<bool> seen(10001, false);
        int total = nums.size();
        for (int num : nums)
        {
            if (seen[num])
                return num;
            seen[num] = true;
        }

        return -1;
    }
};

/*

we know both the lower and upper bounds of n, we can use a fixed size array of booleans to store the seen map, and identify the element already traversed

*/
