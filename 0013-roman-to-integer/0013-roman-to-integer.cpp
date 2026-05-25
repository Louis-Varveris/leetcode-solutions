class Solution 
{
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> roman = 
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int result = 0;
        // Start at the first character of the Roman numeral.
        // Move through the string one character at a time.
        for(int i = 0; i < s.length(); i++)
        {
            // This compares the value of the current Roman numeral with the next one.
            if(i < s.length()-1 && roman[s[i]] < roman[s[i+1]]) 
                result -= roman[s[i]]; // this means it's a subtraction case.
            else
                result += roman[s[i]]; // If the next number is not bigger, we just add it normally.
        }
        return result;
    }
};