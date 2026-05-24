class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0) 
        {
            return false;
        }
        if (x % 10 == 0 && x != 0) 
        {
            return false;
        }
        int reversed = 0;
        while (x > reversed) 
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        // For even length: x == reversedHalf
        // For odd length: x == reversedHalf / 10
        return (x == reversed || x == reversed / 10);
    }
};
// These two lines:
// Take the last digit of x
// Add it to the reversed number
// Remove that last digit from x
// So we are:
// Peeling digits off from the right
// Building a reversed number from them