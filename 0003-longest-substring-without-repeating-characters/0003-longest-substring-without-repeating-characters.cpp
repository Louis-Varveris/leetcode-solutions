#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> last(256, -1);   
        int left = 0;
        int best = 0;
        for (int right = 0; right < (int)s.size(); right++) 
        {
            unsigned char c = s[right];
            if (last[c] >= left) 
            {
                left = last[c] + 1;
            }
            last[c] = right;                
            best = max(best, right - left + 1);
        }
        return best;
    }
};