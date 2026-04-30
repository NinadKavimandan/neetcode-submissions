class Solution {
public:
    int trap(vector<int>& height) 
    {
        int length = height.size();
        int totalArea = 0;
        vector<int> leftWall(length, 0);
        vector<int> rightWall(length, 0);

        leftWall[0] = height[0];
        rightWall[length - 1] = height[length - 1];

        for (int index=1;index<length;index++)
        {
            leftWall[index] = max(leftWall[index - 1], height[index]);
        }

        for (int index=length-2;index>-1;index--)
        {
            rightWall[index] = max(rightWall[index + 1], height[index]);
        }

        for (int index=0;index < length;index++)
        {
            totalArea += min(leftWall[index], rightWall[index]) - height[index];
        }

        return totalArea;
    }
};

/*

wow this is difficult.
we need to look for packets of certain sizes which can store water.
start should be higher or equal to lower to end for water to be trapped.
use two pointers, n and n + 1, move them forward till start is greater than 0, and end is less than start.
count cells in between each time you move end.

why is this correct? instead of findings area using height*width, you need to count cells using the height difference between start and end, as the pocket may not always be rectangular, so it tursn
this wouldn't work, tall walls can be on either side. you need to have knowledge of what's the tallest wall on either side for an element, and trap water based on whatever wall is lower.

*/