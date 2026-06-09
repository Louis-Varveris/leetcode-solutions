class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        // If either number is 0, the product is 0
        if (num1 == "0" || num2 == "0") 
        {
            return "0";
        }
        int n = num1.size();
        int m = num2.size();
        // Maximum possible digits in the result is n + m
        vector<int> result(n + m, 0);
        // Multiply each digit of num1 with each digit of num2
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--) 
            {
                // Convert characters to integers
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                // Multiply the two digits
                int product = digit1 * digit2;
                // Positions where the result contributes
                int pos1 = i + j;
                int pos2 = i + j + 1;
                // Add current product to existing value
                int sum = product + result[pos2];
                // Store carry and remainder
                result[pos1] += sum / 10;
                result[pos2] = sum % 10;
            }
        }
        string answer = "";
        // Skip leading zeros
        int i = 0;
        while (i < result.size() && result[i] == 0) 
        {
            i++;
        }
        // Convert digits back into a string
        while (i < result.size()) 
        {
            answer += result[i] + '0';
            i++;
        }
        return answer;
    }
};