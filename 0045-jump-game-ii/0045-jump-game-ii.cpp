class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        // Number of jumps taken so far
        int jumps = 0;
        // End of the range we can reach with the current jump
        int currentEnd = 0;
        // Farthest index we can reach while scanning this range
        int farthest = 0;
        // We do not need to jump from the last index
        for (int i = 0; i < nums.size() - 1; i++) 
        {
            // Update the farthest place we can reach from index i
            farthest = max(farthest, i + nums[i]);
            // If we reached the end of the current jump range,
            // we must make another jump
            if (i == currentEnd) 
            {
                jumps++;
                // The next jump can reach up to farthest
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};