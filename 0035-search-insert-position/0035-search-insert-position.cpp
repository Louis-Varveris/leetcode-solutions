class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        // left points to the start of the search range
        int left = 0;
        // right points to the end of the search range
        int right = nums.size() - 1;
        // Keep searching while the range is valid
        while (left <= right) 
        {
            // Find the middle index
            // This avoids possible overflow compared to (left + right) / 2
            int mid = left + (right - left) / 2;
            // If we found the target, return its index
            if (nums[mid] == target) 
            {
                return mid;
            }
            // If the middle value is smaller than the target,
            // the target should be on the right side
            if (nums[mid] < target) 
            {
                left = mid + 1;
            } 
            // If the middle value is greater than the target,
            // the target should be on the left side
            else 
            {
                right = mid - 1;
            }
        }
        // If target was not found, left is the correct insert position.
        // Why?
        // left is the first index where nums[left] would be >= target.
        return left;
    }
};