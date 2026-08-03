class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<pair<int, int>> larger;
        int maxArea = INT_MIN;
        int total = heights.size();

        for (int index = 0;index<total;index++)
        {
            int start = index;
            while (!larger.empty() && heights[larger.top().first] > heights[index])
            {
                maxArea = max(maxArea, heights[larger.top().first]*(index - larger.top().second));
                start = larger.top().second;
                larger.pop();
            }

            larger.push({ index, start });
        }

        while (!larger.empty())
        {
            maxArea = max(maxArea, heights[larger.top().first]*(total - larger.top().second));
            larger.pop();
        }

        return maxArea;
    }
};