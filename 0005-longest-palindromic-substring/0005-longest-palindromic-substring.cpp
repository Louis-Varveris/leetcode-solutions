class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = (int)s.size();
        if (n <= 1) return s;
        int bestL = 0, bestR = 0; // inclusive bounds of best palindrome
        auto expand = [&](int l, int r) 
        {
            while (l >= 0 && r < n && s[l] == s[r]) 
            {
                l--;
                r++;
            }
            // we expanded one step too far
            l++;
            r--;
            if (r - l > bestR - bestL) 
            {
                bestL = l;
                bestR = r;
            }
        };
        for (int i = 0; i < n; i++) 
        {
            expand(i, i);       // odd-length center
            expand(i, i + 1);   // even-length center
        }
        return s.substr(bestL, bestR - bestL + 1);
    }
};