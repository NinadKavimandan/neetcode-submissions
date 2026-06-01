class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int result = 0;
        
        for (int iter = 1;iter < nums.size();iter++)
        {
            if (nums[iter] < nums[iter-1])
            {
                result = iter;
                break;
            }
        }

        return nums[result];
    }
};

/*

since the question asks to be solved in logn, it has be divide and conquer.
binary search comes to mind.

*/