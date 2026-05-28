class Solution 
{
public:
    string countAndSay(int n) 
    {
        // The first term in the count-and-say sequence is always "1"
        string result = "1";
        // Build the sequence from term 2 up to term n
        for (int i = 2; i <= n; i++) 
        {
            // This will store the next term in the sequence
            string next = "";
            // Start checking the first character of the current result
            int index = 0;
            // Go through the whole current string
            while (index < result.length()) 
            {
                // Count how many times the current digit repeats in a row
                int count = 1;
                // Keep moving while the next digit is the same
                while (index + 1 < result.length() &&
                       result[index] == result[index + 1]) 
                       {
                    count++;
                    index++;
                }
                // Add the count, then the digit itself
                // Example: "111" becomes "31"
                next += to_string(count);
                next += result[index];
                // Move to the next different digit
                index++;
            }
            // Update result to the newly created term
            result = next;
        }
        // Return the nth term
        return result;
    }
};