class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        vector<int> numbers;
        int factorial = 1;
        // Build list of available digits
        // and calculate (n-1)!
        for (int i = 1; i < n; i++) 
        {
            factorial *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        // Convert to 0-based indexing
        k--;
        string result;
        while (!numbers.empty()) 
        {
            // Find which block k belongs to
            int index = k / factorial;
            // Add that digit to answer
            result += to_string(numbers[index]);
            // Remove used digit
            numbers.erase(numbers.begin() + index);
            // No more digits left
            if (numbers.empty())
                break;
            // Update k for next position
            k %= factorial;
            // update factorial
            factorial /= numbers.size();
        }
        return result;
    }
};