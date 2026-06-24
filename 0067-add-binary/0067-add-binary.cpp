class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        // Pointers starting at the last character of each string
        int i = a.size() - 1;
        int j = b.size() - 1;
        // Stores the carry value during addition
        int carry = 0;
        // Stores the binary sum (built in reverse order)
        string result = "";
        // Continue while there are digits left in either string
        // or there is still a carry to process
        while (i >= 0 || j >= 0 || carry) 
        {
            // Start with the carry from the previous addition
            int sum = carry;
            // Add current digit from string a if available
            if (i >= 0) 
            {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            // Add current digit from string b if available
            if (j >= 0) 
            {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }
            // Current binary digit is sum % 2
            result += (sum % 2) + '0';
            // Carry is sum / 2
            carry = sum / 2;
        }
        // Digits were added from right to left,
        // so reverse the result to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};