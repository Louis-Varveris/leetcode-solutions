class Solution 
{
public:
    int climbStairs(int n) 
    {
        // Base cases
        if (n <= 2)
            return n;
        // ways to reach step 1 and step 2
        int first = 1;
        int second = 2;
        // Calculate ways from step 3 up to step n
        for (int i = 3; i <= n; i++)
        {
            int current = first + second;
            // Shift values forward
            first = second;
            second = current;
        }
        return second;
    }
};