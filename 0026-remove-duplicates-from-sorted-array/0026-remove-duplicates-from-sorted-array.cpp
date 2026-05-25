class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int k = 1; //Because the first element is always unique, so we keep it.
        for (int i = 1; i < nums.size(); i++) //For each number, we compare it with the last unique number:
        {
            if (nums[i] != nums[k - 1]) //If it is different, then it is a new unique number. So we place it at index k
            {
                nums[k] = nums[i]; //If it is different, then it is a new unique number. So we place it at index k
                k++; //At the end, k is the number of unique elements.
            }
        }
        return k;
    }
};