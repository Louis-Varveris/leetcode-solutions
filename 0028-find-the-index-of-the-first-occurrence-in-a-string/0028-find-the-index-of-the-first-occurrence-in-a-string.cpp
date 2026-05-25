class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        // If needle is longer than haystack, it cannot be found
        if (needle.length() > haystack.length()) 
        {
            return -1;
        }
        // Go through each possible starting index in haystack
        for (int i = 0; i <= haystack.length() - needle.length(); i++) 
        {
            // Assume the substring starting at i matches needle
            bool match = true;
            // Check every character of needle
            for (int j = 0; j < needle.length(); j++) 
            {
                // If characters do not match, this is not the right starting index
                if (haystack[i + j] != needle[j]) 
                {
                    match = false;
                    break;
                }
            }
            // If every character matched, return the first starting index
            if (match) 
            {
                return i;
            }
        }
        // If needle was never found
        return -1;
    }
};