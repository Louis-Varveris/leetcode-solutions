class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        // Create an n x n matrix filled with 0s
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        // These variables represent the current boundaries
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        // Number we are placing into the matrix
        int num = 1;
        // Keep going until all numbers from 1 to n^2 are placed
        while (num <= n * n) 
        {
            // Move left to right across the top row
            for (int col = left; col <= right; col++) 
            {
                matrix[top][col] = num;
                num++;
            }
            top++;
            // Move top to bottom down the right column
            for (int row = top; row <= bottom; row++) 
            {
                matrix[row][right] = num;
                num++;
            }
            right--;
            // Move right to left across the bottom row
            for (int col = right; col >= left; col--) 
            {
                matrix[bottom][col] = num;
                num++;
            }
            bottom--;
            // Move bottom to top up the left column
            for (int row = bottom; row >= top; row--) 
            {
                matrix[row][left] = num;
                num++;
            }
            left++;
        }
        return matrix;
    }
};