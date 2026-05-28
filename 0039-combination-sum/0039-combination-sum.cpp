class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        // This will store all valid combinations
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
                   vector<vector<int>>& result) {

        // If target becomes 0, we found a valid combination
        if (target == 0) 
        {
            result.push_back(current);
            return;
        }
        // If target becomes negative, this path is invalid
        if (target < 0) 
        {
            return;
        }
        // Try each candidate starting from the current index
        for (int i = start; i < candidates.size(); i++) 
        {
            // Add the current candidate to the combination
            current.push_back(candidates[i]);
            // Because we can reuse the same number,
            // we pass i instead of i + 1
            backtrack(candidates, target - candidates[i], i, current, result);
            // Remove the last number and try another choice
            current.pop_back();
        }
    }
};