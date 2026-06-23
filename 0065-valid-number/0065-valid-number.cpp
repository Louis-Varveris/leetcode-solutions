class Solution 
{
public:
    bool isNumber(string s) 
    {
        bool seenDigit = false;     // Have we seen at least one digit?
        bool seenDot = false;       // Have we seen a decimal point?
        bool seenExponent = false;  // Have we seen e or E?
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            // Digit is always valid
            if (isdigit(c))
            {
                seenDigit = true;
            }
            // Handle '+' or '-'
            else if (c == '+' || c == '-')
            {
                // Sign is only valid:
                // 1. At the beginning
                // 2. Immediately after e or E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            // Handle decimal point
            else if (c == '.')
            {
                // Cannot have multiple dots
                // Cannot have a dot after an exponent
                if (seenDot || seenExponent)
                    return false;

                seenDot = true;
            }
            // Handle exponent
            else if (c == 'e' || c == 'E')
            {
                // Cannot have multiple exponents
                // Must have a number before e/E
                if (seenExponent || !seenDigit)
                    return false;

                seenExponent = true;

                // Reset digit flag because
                // we need digits AFTER the exponent too
                seenDigit = false;
            }
            // Any other character is invalid
            else
            {
                return false;
            }
        }
        // Must end with a digit
        return seenDigit;
    }
};