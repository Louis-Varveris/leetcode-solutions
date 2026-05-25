class Solution 
{
public:
    void solve(int index, string digits, string current, vector<string>& result, vector<string>& phone)
    {
        if(index == digits.length())
        {
            result.push_back(current); // Adds the completed combination to the result list.
            return;
        }
        string letters = phone[digits[index] - '0']; // Gets the digit and coverts the character into a number.
        for(char c : letters) // Loops through all the letters.
        {
            solve(index + 1, digits, current + c, result, phone); // Moves to the next digit, adds the chosen letter. 
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty()) return {};
        vector<string> phone = 
        {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        solve(0, digits, "", result, phone);
        return result;
    }
};