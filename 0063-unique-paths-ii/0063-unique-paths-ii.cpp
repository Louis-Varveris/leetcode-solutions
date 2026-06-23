class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();       // Number of rows
        int n = obstacleGrid[0].size();    // Number of columns
        // dp[row][col] = number of ways to reach this cell
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        // If starting cell is blocked, no path exists
        if (obstacleGrid[0][0] == 1)
            return 0;
        // Start position has one way to be reached
        dp[0][0] = 1;
        // Fill the DP table
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // If current cell is an obstacle,
                // no path can go through it
                if (obstacleGrid[row][col] == 1)
                {
                    dp[row][col] = 0;
                    continue;
                }
                // Add paths coming from the cell above
                if (row > 0)
                    dp[row][col] += dp[row - 1][col];

                // Add paths coming from the cell to the left
                if (col > 0)
                    dp[row][col] += dp[row][col - 1];
            }
        }
        // Bottom-right cell contains the answer
        return dp[m - 1][n - 1];
    }
};