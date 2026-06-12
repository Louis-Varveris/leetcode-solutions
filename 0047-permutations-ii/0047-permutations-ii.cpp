class Solution 
{
public:
vector<vector<int>> result;
    void backtrack(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& current) 
                   {
        // If we have chosen all numbers,
        // we found one complete permutation.
        if (current.size() == nums.size()) 
        {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) 
        {
            // Skip numbers already used in this permutation.
            if (used[i])
                continue;
            // Skip duplicates.
            // Example: [1,1,2]
            // If the previous identical number was not used,
            // choosing this one would create a duplicate permutation.
            if (i > 0 &&
                nums[i] == nums[i - 1] &&
                !used[i - 1])
                continue;
            // Choose nums[i]
            used[i] = true;
            current.push_back(nums[i]);
            // Explore further
            backtrack(nums, used, current);
            // Undo choice (backtrack)
            current.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        // Sort so duplicates are adjacent.
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> current;
        backtrack(nums, used, current);
        return result;
    }
};