class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int start = 0;
        int cols = matrix[0].size();
        int end = matrix.size()*cols;

        while (start < end)
        {
            int mid = (start + end)/2;
            if (matrix[mid/cols][mid%cols] == target)
            {
                return true;
            }

            if (matrix[mid/cols][mid%cols] > target)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return false;
    }
};

/*

treat the matrix as a folded array, and apply binary search logic directly.
shrink the window based on how the mid element trades with the target.

*/