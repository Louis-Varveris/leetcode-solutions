class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        // k keeps track of where the next valid element should go
        int k = 0;
        // Go through every element in the array
        for (int i = 0; i < nums.size(); i++) 
        { 
            // If the current element is NOT equal to val,
            // then we want to keep it
            if (nums[i] != val) 
            {
                // Move this valid element to position k
                nums[k] = nums[i];
                // Move k forward because we found one more valid element
                k++;
            }
        }
        // k is the number of elements that are not equal to val
        return k;
    }
};