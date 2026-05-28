class Solution 
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        // Sort the array so duplicate numbers are next to each other.
        // This helps us skip duplicate combinations.
        sort(candidates.begin(), candidates.end());
        // This will store all valid unique combinations
        vector<vector<int>> result;
        // This will store the current combination we are building
        vector<int> current;
        // Start backtracking from index 0
        backtrack(candidates, target, 0, current, result);
        // Return all valid combinations
        return result;
    }
private:
    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current,
                   vector<vector<int>>& result) 
                   {
        // If target becomes 0, the current combination is valid
        if (target == 0) 
        {
            result.push_back(current);
            return;
        }
        // Try each number starting from the current index
        for (int i = start; i < candidates.size(); i++) 
        {
            // Skip duplicate numbers at the same recursion level.
            // This prevents duplicate combinations in the answer.
            if (i > start && candidates[i] == candidates[i - 1]) 
            {
                continue;
            }
            // Since the array is sorted, if this number is bigger than
            // the remaining target, no later number will work either.
            if (candidates[i] > target) 
            {
                break;
            }
            // Choose the current number
            current.push_back(candidates[i]);
            // Move to i + 1 because each number can only be used once
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            // Undo the choice and try another number
            current.pop_back();
        }
    }
};