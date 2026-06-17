class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        // This will store the final spiral order
        vector<int> result;
        // Get number of rows and columns
        int rows = matrix.size();
        int cols = matrix[0].size();
        // Boundaries of the matrix
        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;
        // Keep going while the boundaries are valid
        while (top <= bottom && left <= right) 
        {
            // Move left to right across the top row
            for (int i = left; i <= right; i++) 
            {
                result.push_back(matrix[top][i]);
            }
            top++;
            // Move top to bottom down the right column
            for (int i = top; i <= bottom; i++) 
            {
                result.push_back(matrix[i][right]);
            }
            right--;
            // Move right to left across the bottom row
            if (top <= bottom) 
            {
                for (int i = right; i >= left; i--) 
                {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // Move bottom to top up the left column
            if (left <= right) 
            {
                for (int i = bottom; i >= top; i--) 
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};