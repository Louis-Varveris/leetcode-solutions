class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        // Step 1: Transpose the matrix
        // This swaps rows with columns.
        // Example:
        // 1 2 3      1 4 7
        // 4 5 6  ->  2 5 8
        // 7 8 9      3 6 9
        for (int row = 0; row < n; row++)
        {
            for (int col = row + 1; col < n; col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        // Step 2: Reverse each row
        // Example:
        // 1 4 7      7 4 1
        // 2 5 8  ->  8 5 2
        // 3 6 9      9 6 3
        for (int row = 0; row < n; row++)
        {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};