class Solution 
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> result;
        int i = 0;
        while (i < words.size()) 
        {
            // Find how many words fit in the current line
            int j = i;
            int lineLength = 0;
            while (j < words.size() &&
                   lineLength + words[j].size() + (j - i) <= maxWidth) 
                   {
                lineLength += words[j].size();
                j++;
            }
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength;
            string line;
            // Case 1: Last line OR only one word
            if (j == words.size() || numWords == 1) 
            {
                // Add words separated by a single space
                line += words[i];
                for (int k = i + 1; k < j; k++) 
                {
                    line += " ";
                    line += words[k];
                }
                // Pad remaining spaces at the end
                while (line.size() < maxWidth) 
                {
                    line += " ";
                }
            }
            else 
            {
                // Number of gaps between words
                int gaps = numWords - 1;
                // Minimum spaces per gap
                int spacesPerGap = totalSpaces / gaps;
                // Extra spaces that go to leftmost gaps
                int extraSpaces = totalSpaces % gaps;
                for (int k = i; k < j; k++) 
                {
                    line += words[k];
                    // Don't add spaces after the last word
                    if (k < j - 1) 
                    {
                        // Every gap gets base spaces
                        line += string(spacesPerGap, ' ');
                        // Leftmost gaps get one extra space
                        if (extraSpaces > 0) 
                        {
                            line += " ";
                            extraSpaces--;
                        }
                    }
                }
            }
            result.push_back(line);
            // Move to next group of words
            i = j;
        }
        return result;
    }
};