class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        // currentSum stores the best subarray sum ending at the current index
        int currentSum = nums[0];
        // maxSum stores the best subarray sum found so far
        int maxSum = nums[0];
        // Start from index 1 because nums[0] is already used
        for (int i = 1; i < nums.size(); i++) 
        {
            // Either:
            // 1. Start a new subarray at nums[i]
            // 2. Continue the previous subarray by adding nums[i]
            currentSum = max(nums[i], currentSum + nums[i]);
            // Update maxSum if the current subarray is better
            maxSum = max(maxSum, currentSum);
        }
        // Return the largest subarray sum
        return maxSum;
    }
};