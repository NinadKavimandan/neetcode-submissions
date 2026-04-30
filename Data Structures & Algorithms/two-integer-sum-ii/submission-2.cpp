class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int start = 0;
        int end = numbers.size() - 1;
        vector<int> response;
        while (true)
        {
            int curSum = numbers[start] + numbers[end];
            if (curSum > target)
            {
                end--;
            }
            else if (curSum < target)
            {
                start++;
            }
            else
            {
                response.push_back(start + 1);
                response.push_back(end + 1);
                break;
            }
        }

        return response;
    }
};

/*

we can potentially use two pointer method here too.
start points to first index, end to last
if (start + end) < target,
start++
else if (start + end) > target
end--

since it is confirmed there is guaranteed to be a single solution, and the elements are sorted non-decreasing manner, this approach should end us up in the right set of indices.

*/