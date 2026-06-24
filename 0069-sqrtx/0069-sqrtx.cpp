class Solution 
{
public:
    int mySqrt(int x) 
    {
        // Special cases
        if (x == 0 || x == 1)
            return x;
        long long left = 1;
        long long right = x;
        int answer = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            if (square == x)
            {
                return mid;
            }
            else if (square < x)
            {
                // mid could be the answer
                answer = mid;
                left = mid + 1;
            }
            else
            {
                // Need a smaller value
                right = mid - 1;
            }
        }
        return answer;
    }
};