class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        for (int i = digits.size() - 1; i >= 0; i--) 
        {
            if (digits[i] < 9) 
            {
                digits[i]++; //adds 1 to last digit
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};