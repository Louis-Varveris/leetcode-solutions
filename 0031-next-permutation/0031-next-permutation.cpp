class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        // Start from the second-to-last index.
        // We are looking for the first number from the right
        // that is smaller than the number after it.
        int i = n - 2;
        // Move left while the current number is greater than or equal
        // to the number after it.
        // This finds the point where the descending order stops.
        while (i >= 0 && nums[i] >= nums[i + 1]) 
        {
            i--;
        }
        // If i is still valid, it means we found a number that can be increased.
        // Example: in [1, 2, 3], nums[1] = 2 can be increased by swapping with 3.
        if (i >= 0) 
        {
            // Start from the last index.
            int j = n - 1;
            // Find the first number from the right that is greater than nums[i].
            // This number will be swapped with nums[i].
            while (nums[j] <= nums[i]) 
            {
                j--;
            }
            // Swap nums[i] with the next greater number.
            swap(nums[i], nums[j]);
        }
        // Reverse the part after index i.
        //
        // Why?
        // The suffix was in descending order, so reversing it makes it ascending,
        // giving us the smallest possible arrangement after the swap.
        // If no valid i was found, i == -1, so this reverses the whole array.
        // Example: [3, 2, 1] becomes [1, 2, 3].
        reverse(nums.begin() + i + 1, nums.end());
    }
};