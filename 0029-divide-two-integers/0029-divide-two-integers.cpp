class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        // Special overflow case:
        // -2147483648 / -1 = 2147483648, which is bigger than INT_MAX
        if (dividend == INT_MIN && divisor == -1) 
        {
            return INT_MAX;
        }
        // Convert to long long first so INT_MIN can safely become positive
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        // Use long long because the temporary answer can be bigger than int
        long long result = 0;
        // Keep subtracting chunks of divisor from dividend
        while (a >= b) 
        {
            // Start with one divisor
            long long temp = b;
            // This tracks how many divisors temp represents
            long long multiple = 1;
            // Double temp while it still fits into a
            while (a >= (temp << 1)) 
            {
                temp <<= 1;
                multiple <<= 1;
            }
            // Remove the largest doubled divisor from a
            a -= temp;
            // Add how many divisors we removed
            result += multiple;
        }
        // If one number is negative and the other is positive,
        // the final answer should be negative
        if ((dividend < 0) ^ (divisor < 0)) 
        {
            result = -result;
        }
        // Return the result as an int
        return (int)result;
    }
};