class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        // left and right are the current search boundaries
        int left = 0;
        int right = nums.size() - 1;
        // Standard binary search loop
        while (left <= right) 
        {
            // Find the middle index
            // This avoids overflow compared to (left + right) / 2
            int mid = left + (right - left) / 2;
            // If the middle element is the target, return its index
            if (nums[mid] == target) 
            {
                return mid;
            }
            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) 
            {
                // If target is inside the sorted left half,
                // search only the left half
                if (nums[left] <= target && target < nums[mid]) 
                {
                    right = mid - 1;
                } 
                else 
                {
                    // Otherwise, search the right half
                    left = mid + 1;
                }
            } 
            else {
                // Otherwise, the right half must be sorted
                // If target is inside the sorted right half,
                // search only the right half
                if (nums[mid] < target && target <= nums[right]) 
                {
                    left = mid + 1;
                } 
                else 
                {
                    // Otherwise, search the left half
                    right = mid - 1;
                }
            }
        }
        // If we finish the loop, target was not found
        return -1;
    }
};