class Solution 
{
public:
    // Stores all valid board configurations
    vector<vector<string>> ans;
    // Current board being built
    vector<string> board;
    // Tracks which columns already contain a queen
    vector<int> col;
    // Tracks the main diagonals (top-left -> bottom-right)
    vector<int> diag1;
    // Tracks the anti-diagonals (top-right -> bottom-left)
    vector<int> diag2;
    // Backtracking function
    void backtrack(int row, int n) 
    {
        // Base case:
        // If we've successfully placed queens in all rows,
        // save the current board configuration.
        if (row == n) 
        {
            ans.push_back(board);
            return;
        }
        // Try placing a queen in every column of the current row
        for (int c = 0; c < n; c++) 
        {
            // Check if the position is under attack
            if (col[c] ||                 // same column
                diag1[row + c] ||         // main diagonal
                diag2[row - c + n - 1])   // anti-diagonal
            {
                continue;
            }
            // Place the queen
            board[row][c] = 'Q';
            // Mark column and diagonals as occupied
            col[c] = 1;
            diag1[row + c] = 1;
            diag2[row - c + n - 1] = 1;
            // Move to the next row
            backtrack(row + 1, n);
            // BACKTRACK:
            // Remove queen and undo markings
            board[row][c] = '.';
            col[c] = 0;
            diag1[row + c] = 0;
            diag2[row - c + n - 1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        // Create an empty n x n board filled with '.'
        board = vector<string>(n, string(n, '.'));
        // Column tracking array
        col = vector<int>(n, 0);
        // There are (2*n - 1) possible diagonals
        diag1 = vector<int>(2 * n - 1, 0);
        diag2 = vector<int>(2 * n - 1, 0);
        // Start placing queens from row 0
        backtrack(0, n);
        return ans;
    }
};