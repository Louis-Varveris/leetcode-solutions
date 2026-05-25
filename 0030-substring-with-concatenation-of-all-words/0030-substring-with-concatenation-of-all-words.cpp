class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> result; // stores the answer indices
        // Edge case: if words is empty or s is empty
        if (s.empty() || words.empty()) 
        {
            return result;
        }
        int wordLen = words[0].size();      // Length of each word
        int wordCount = words.size();       // Number of words
        int totalLen = wordLen * wordCount; // Total length of a valid substring
        // If s is shorter than the needed total length, no answer is possible
        if (s.size() < totalLen) 
        {
            return result;
        }
        // Store the frequency of each word we need to match
        unordered_map<string, int> wordFreq;
        for (string word : words) 
        {
            wordFreq[word]++;
        }
        /*
            We use sliding window, but we must start from different offsets.
            Example:
            wordLen = 3
            We check groups starting at:
            offset 0: s[0..2], s[3..5], s[6..8]
            offset 1: s[1..3], s[4..6], s[7..9]
            offset 2: s[2..4], s[5..7], s[8..10]
        */
        for (int offset = 0; offset < wordLen; offset++) 
        {
            unordered_map<string, int> seen;
            int left = offset;  // Left side of sliding window
            int count = 0;      // Number of valid words currently in window
            // Move right pointer by wordLen each time
            for (int right = offset; right + wordLen <= s.size(); right += wordLen) 
            {
                string word = s.substr(right, wordLen);
                // If this word is one of the required words
                if (wordFreq.count(word)) 
                {
                    seen[word]++;
                    count++;
                    /*
                        If this word appears too many times,
                        shrink the window from the left
                        until the frequency becomes valid again.
                    */
                    while (seen[word] > wordFreq[word]) 
                    {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    /*
                        If the window contains exactly wordCount words,
                        then we found a valid starting index.
                    */
                    if (count == wordCount) 
                    {
                        result.push_back(left);
                        /*
                            Move left forward to continue searching
                            for the next possible answer.
                        */
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } 
                else 
                {
                    /*
                        If the word is not in words,
                        reset the window completely.
                    */
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};