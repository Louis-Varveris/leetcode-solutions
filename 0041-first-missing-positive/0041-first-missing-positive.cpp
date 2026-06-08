class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        // Place each number x at index (x - 1)
        // Example: 1 -> index 0, 2 -> index 1, 3 -> index 2, etc.
        int n = nums.size();
        for (int i = 0; i < n; i++) 
        {
            // Keep swapping until:
            // 1. nums[i] is out of range [1, n], OR
            // 2. nums[i] is already in its correct position
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) 
            {
                // Put nums[i] into its correct position
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // After rearranging:
        // nums[i] should equal i + 1
        for (int i = 0; i < n; i++) 
        {
            // First mismatch means the missing positive is i + 1
            if (nums[i] != i + 1) 
            {
                return i + 1;
            }
        }
        // If all positions are correct,
        // the missing positive is n + 1
        return n + 1;
    }
};