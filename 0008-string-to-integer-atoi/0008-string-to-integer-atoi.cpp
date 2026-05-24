class Solution 
{
public:
    int myAtoi(string s) 
    {
        int i = 0;
        int n = s.length();
        // 1. Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;
        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) 
        {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        // 3. Convert digits
        long result = 0;  // use long to detect overflow
        while (i < n && isdigit(s[i])) 
        {
            int digit = s[i] - '0';
            // 4. Check overflow
            if (result > (INT_MAX - digit) / 10) 
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }
        return sign * result;
    }
};
// result = 0 * 10 + 4 = 4
// result = 4 * 10 + 2
// 4  →  40
// 40 + 2 = 42