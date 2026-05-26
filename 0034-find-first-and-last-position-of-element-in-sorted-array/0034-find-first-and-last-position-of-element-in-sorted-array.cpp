class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        // Find the first occurrence of target
        int first = findFirst(nums, target);
        // Find the last occurrence of target
        int last = findLast(nums, target);
        // Return both positions
        return {first, last};
    }
private:
    int findFirst(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        // Default answer if target is not found
        int result = -1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) 
            {
                // We found target, but there may be another one earlier
                result = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) 
            {
                // Target must be on the right side
                left = mid + 1;
            }
            else 
            {
                // Target must be on the left side
                right = mid - 1;
            }
        }
        return result;
    }
    int findLast(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        // Default answer if target is not found
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) 
            {
                // We found target, but there may be another one later
                result = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) 
            {
                // Target must be on the right side
                left = mid + 1;
            }
            else 
            {
                // Target must be on the left side
                right = mid - 1;
            }
        }
        return result;
    }
};