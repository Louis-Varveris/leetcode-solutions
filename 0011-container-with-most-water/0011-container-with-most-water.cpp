class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while (left < right) 
        {
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;
            maxWater = max(maxWater, area);
            // Move the smaller height
            if (height[left] < height[right]) 
            {
                left++;
            } else 
            {
                right--;
            }
        }
        return maxWater;
    }
};
// [1,8,6,2,5,4,8,3,7]
// left = 1 (8)
// right = 8 (7)
// width = 7
// area = 7 * 7 = 49  ← max because right - left = 8 - 1 = 7, then 7 times 7 equals 49. Always limited by the shorter wall. 