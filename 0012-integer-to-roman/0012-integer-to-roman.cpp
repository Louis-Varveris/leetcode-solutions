class Solution 
{
public:
    string intToRoman(int num) 
    {
         // Values include subtractive forms
        vector<pair<int, string>> roman = 
        {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"}
        };
        string result;
        // It loops through the vector:
        // p.first  -> number value
        // p.second -> Roman symbol
        for (auto &p : roman) 
        {
            int value = p.first;
            string symbol = p.second;
            while (num >= value) // Can the Roman value fit inside the number? 
            {
                result += symbol; // This appends the Roman symbol to the result string.
                num -= value; // We remove the value we just used.
            }
        }
        return result;
    }
};