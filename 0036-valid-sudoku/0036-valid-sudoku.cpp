class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // This set keeps track of every number we have already seen
        // in each row, column, and 3x3 box.
        unordered_set<string> seen;
        // Go through every row in the 9x9 board
        for (int row = 0; row < 9; row++) 
        {
            // Go through every column in the current row
            for (int col = 0; col < 9; col++) 
            {

                // Get the current cell value
                char num = board[row][col];
                // If the cell is empty, skip it
                if (num == '.') 
                {
                    continue;
                }
                // Create a unique record for this number in this row
                string rowCheck = "row " + to_string(row) + " has " + num;
                // Create a unique record for this number in this column
                string colCheck = "col " + to_string(col) + " has " + num;
                // Create a unique record for this number in this 3x3 box
                // row / 3 gives the box row, col / 3 gives the box column
                string boxCheck = "box " + to_string(row / 3) + "-" + to_string(col / 3) + " has " + num;
                // If this number was already seen in the same row,
                // same column, or same 3x3 box, the board is invalid
                if (seen.count(rowCheck) || seen.count(colCheck) || seen.count(boxCheck)) 
                {
                    return false;
                }
                // Store the current number's row, column, and box records
                seen.insert(rowCheck);
                seen.insert(colCheck);
                seen.insert(boxCheck);
            }
        }
        // If no duplicate was found, the Sudoku board is valid
        return true;
    }
};