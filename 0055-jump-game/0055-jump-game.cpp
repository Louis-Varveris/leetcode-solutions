class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        // Stores the farthest index we can currently reach
        int maxReach = 0;
        // Traverse the array
        for (int i = 0; i < nums.size(); i++) 
        {
            // If current index is beyond our reachable range,
            // then we cannot continue
            if (i > maxReach) 
            {
                return false;
            }
            // Update the farthest position we can reach
            // from the current index
            maxReach = max(maxReach, i + nums[i]);
            // If we can already reach or pass the last index,
            // return true immediately
            if (maxReach >= nums.size() - 1) 
            {
                return true;
            }
        }
        // If we finish the loop, the last index is reachable
        return true;
    }
};