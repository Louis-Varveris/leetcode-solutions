class Solution 
{
public:
    // Stores the total number of valid solutions found
    int count = 0;
    // Backtracking function that tries to place a queen row by row
    void backtrack(int row,
                   int n,
                   vector<int>& col,
                   vector<int>& diag1,
                   vector<int>& diag2) 
                   {
        // Base case:
        // If we've reached row n, then queens have been
        // successfully placed in all rows.
        if (row == n) 
        {
            count++; // Found one valid arrangement
            return;
        }
        // Try placing a queen in every column of the current row
        for (int c = 0; c < n; c++) 
        {
            // Check if this position is under attack
            if (col[c] ||                 // Same column occupied
                diag1[row + c] ||         // Main diagonal occupied
                diag2[row - c + n - 1])  // Anti-diagonal occupied
            {
                continue;
            }
            // Mark column as occupied
            col[c] = 1;
            // Mark main diagonal as occupied
            diag1[row + c] = 1;
            // Mark anti-diagonal as occupied
            diag2[row - c + n - 1] = 1;
            // Move to the next row
            backtrack(row + 1, n, col, diag1, diag2);
            // Remove queen and unmark everything
            col[c] = 0;
            diag1[row + c] = 0;
            diag2[row - c + n - 1] = 0;
        }
    }
    int totalNQueens(int n) 
    {
        // Tracks which columns already contain a queen
        vector<int> col(n, 0);
        // Tracks main diagonals (\)
        // There are 2*n - 1 possible diagonals
        vector<int> diag1(2 * n - 1, 0);
        // Tracks anti-diagonals (/)
        // There are also 2*n - 1 possible diagonals
        vector<int> diag2(2 * n - 1, 0);
        // Start placing queens from row 0
        backtrack(0, n, col, diag1, diag2);
        // Return the number of valid solutions found
        return count;
    }
};