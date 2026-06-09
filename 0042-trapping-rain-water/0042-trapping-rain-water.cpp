class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        // Two pointers at both ends of the array
        int left = 0;
        int right = height.size() - 1;
        // Track the tallest wall seen so far from each side
        int leftMax = 0;
        int rightMax = 0;
        // Total water trapped
        int water = 0;
        while (left < right) 
        {
            // Process the shorter side first
            if (height[left] < height[right]) 
            {
                // Update maximum height on the left
                if (height[left] >= leftMax) 
                {
                    leftMax = height[left];
                }
                else 
                {
                    // Water trapped at this position
                    water += leftMax - height[left];
                }
                left++;
            }
            else 
            {

                // Update maximum height on the right
                if (height[right] >= rightMax) 
                {
                    rightMax = height[right];
                }
                else 
                {
                    // Water trapped at this position
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};