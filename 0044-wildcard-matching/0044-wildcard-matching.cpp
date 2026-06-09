class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int m = s.size();
        int n = p.size();
        // dp[i][j] means:
        // first i characters of s match first j characters of p
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // Empty string matches empty pattern
        dp[0][0] = true;
        // Handle patterns like "*", "**", "***"
        // These can match an empty string
        for (int j = 1; j <= n; j++) 
        {
            if (p[j - 1] == '*') 
            {
                dp[0][j] = dp[0][j - 1];
            }
        }
        // Fill the DP table
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                // If characters match exactly,
                // or pattern has '?', it matches one character
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // '*' can match:
                // 1. empty sequence: dp[i][j - 1]
                // 2. one or more chars: dp[i - 1][j]
                else if (p[j - 1] == '*') 
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        // Does the entire string match the entire pattern?
        return dp[m][n];
    }
};