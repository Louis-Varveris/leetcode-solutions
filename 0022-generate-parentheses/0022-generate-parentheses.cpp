class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result; // stores all valid combinations
        string current; // current string being built
        backtrack(result, current, 0, 0, n);
        return result;
    }
    // open  = number of '(' used so far
    // close = number of ')' used so far
    void backtrack(vector<string>& result, string& current, int open, int close, int n) 
    {
        // Base case: if the string length is 2*n, we used all parentheses
        if (current.size() == 2 * n) 
        {
            result.push_back(current); // valid combination found
            return;
        }
        // Try adding '(' if we still have some left
        if (open < n) 
        {
            current.push_back('(');  // choose '('
            backtrack(result, current, open + 1, close, n); // recurse
            current.pop_back(); // undo choice (backtrack)
        }
        // Try adding ')' only if it won't make the string invalid
        // We can only close if we have more opens than closes
        if (close < open) 
        {
            current.push_back(')'); // choose ')'
            backtrack(result, current, open, close + 1, n); // recurse
            current.pop_back(); // undo choice
        }
    }
};