class Solution 
{
public:
    double myPow(double x, int n) 
    {
         // Use long long because n can be INT_MIN
        long long power = n;
        // If exponent is negative,
        // invert x and make exponent positive.
        if (power < 0) 
        {
            x = 1 / x;
            power = -power;
        }
        double result = 1.0;
        while (power > 0) 
        {
            // If current bit is 1,
            // multiply result by current x.
            if (power % 2 == 1) 
            {
                result *= x;
            }
            // Square the base.
            x *= x;
            // Move to next bit.
            power /= 2;
        }
        return result;
    }
};