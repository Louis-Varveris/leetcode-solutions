class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();       // Number of rows
        int n = grid[0].size();    // Number of columns
        // dp[row][col] = minimum path sum to reach this cell
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // Starting cell
        dp[0][0] = grid[0][0];
        // Fill first row (can only come from the left)
        for (int col = 1; col < n; col++)
        {
            dp[0][col] = dp[0][col - 1] + grid[0][col];
        }
        // Fill first column (can only come from above)
        for (int row = 1; row < m; row++)
        {
            dp[row][0] = dp[row - 1][0] + grid[row][0];
        }
        // Fill the rest of the table
        for (int row = 1; row < m; row++)
        {
            for (int col = 1; col < n; col++)
            {
                // Choose the cheaper path:
                // either from above or from the left
                dp[row][col] =
                    grid[row][col] +
                    min(dp[row - 1][col], dp[row][col - 1]);
            }
        }
        // Bottom-right cell contains the minimum path sum
        return dp[m - 1][n - 1];
    }
};