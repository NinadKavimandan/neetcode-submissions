class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int maximum = 0;
        int curArea = 0;
        int start = 0;
        int end = heights.size() - 1;
        
        while (start < end)
        {
            curArea = min(heights[start], heights[end])*(end-start);
            maximum = max(maximum, curArea);

            if (heights[start] < heights[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }

        return maximum;
    }
};

/*

let's give this a try with two pointers before i go to bed.
start is 0, end is last index.
you move the lesser height each time, compute area, see if that's greater than current max.

*/