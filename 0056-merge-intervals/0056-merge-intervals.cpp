class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // Sort intervals by their starting value.
        // Example:
        // [[8,10],[1,3],[2,6]]
        // becomes
        // [[1,3],[2,6],[8,10]]
        sort(intervals.begin(), intervals.end());
        // Stores our merged intervals
        vector<vector<int>> result;
        // Go through each interval
        for (auto& interval : intervals) 
        {
            // If result is empty OR current interval does not overlap
            // with the last merged interval, add it directly.
            if (result.empty() || interval[0] > result.back()[1]) 
            {
                result.push_back(interval);
            }
            else 
            {
                result.back()[1] =
                    max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};