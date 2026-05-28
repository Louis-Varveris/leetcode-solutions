class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        // Start solving the board using backtracking
        solve(board);
    }
private:
    bool solve(vector<vector<char>>& board) 
    {
        // Go through every cell in the 9x9 board
        for (int row = 0; row < 9; row++) 
        {
            for (int col = 0; col < 9; col++) 
            {
                // If the cell is empty, try placing a number there
                if (board[row][col] == '.') 
                {
                    // Try digits from '1' to '9'
                    for (char num = '1'; num <= '9'; num++) 
                    {
                        // Check if this number can be placed safely
                        if (isValid(board, row, col, num)) {
                            // Place the number temporarily
                            board[row][col] = num;
                            // Recursively try to solve the rest of the board
                            if (solve(board)) 
                            {
                                return true;
                            }
                            // If the number did not lead to a solution,
                            // remove it and try another number
                            board[row][col] = '.';
                        }
                    }
                    // If no number from 1 to 9 works, return false
                    return false;
                }
            }
        }
        // If there are no empty cells left, the board is solved
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char num) 
    {
        // Check if num already exists in the same row,
        // same column, or same 3x3 box
        for (int i = 0; i < 9; i++) 
        {

            // Check the current row
            if (board[row][i] == num) 
            {
                return false;
            }
            // Check the current column
            if (board[i][col] == num) 
            {
                return false;
            }
            // Check the current 3x3 box
            // row / 3 * 3 gives the starting row of the box
            // col / 3 * 3 gives the starting column of the box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == num) 
            {
                return false;
            }
        }
        // If num is not found in row, column, or box, it is valid
        return true;
    }
};