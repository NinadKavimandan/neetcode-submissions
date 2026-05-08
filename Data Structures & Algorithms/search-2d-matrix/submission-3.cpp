class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        int mid = (left + right)/2;
        int columns = matrix[0].size();
        int rows = matrix.size();

        while (left <= right)
        {
            if (matrix[mid/columns][mid%columns] > target)
            {
                right = mid - 1;
            }
            else if (matrix[mid/columns][mid%columns] < target)
            {
                left = mid + 1;
            }
            else
            {
                return true;
            }

            mid = (left + right)/2;
        }

        return false;
    }
};
