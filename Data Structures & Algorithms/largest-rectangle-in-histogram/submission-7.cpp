class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> larger;
        int maxArea = INT_MIN;
        int total = heights.size();
        vector<int> startedAt(total);

        for (int index = 0;index<total;index++)
        {
            int start = index;
            while (!larger.empty() && heights[larger.top()] > heights[index])
            {
                maxArea = max(maxArea, heights[larger.top()]*(index - startedAt[larger.top()]));
                start = startedAt[larger.top()];
                larger.pop();
            }

            larger.push(index);
            startedAt[index] = start;
        }

        while (!larger.empty())
        {
            maxArea = max(maxArea, heights[larger.top()]*(total - startedAt[larger.top()]));
            larger.pop();
        }

        return maxArea;
    }
};