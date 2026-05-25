class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            while(strs[i].find(prefix) != 0) // Finds the prefix. 
            {
                prefix = prefix.substr(0, prefix.length() - 1); // Extracts part of a string.
                if(prefix == "") // If prefix equals nothing.
                    return ""; // Returns nothing. 
            }
        }
        return prefix; // Returns result.
    }
};