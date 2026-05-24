class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1 || s.size() <= numRows)
            return s;
        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;
        for (char c : s) 
        {
            rows[currRow] += c;
            // change direction at top or bottom
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }
        string result;
        for (string row : rows)
            result += row;
        return result;
    }
};
// explain: Row 0: P A H N
// Row 1: A P L S I I G
// Row 2: Y I R
// Written: first: PAY, then go up to P in second row and then up to A in second column of zero row then down to L in third column of first row and then down to I in second column of second row again and repeat. 
// Expanded out: PAYPALISHIRING