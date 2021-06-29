// link - https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return false;
        }
        int pre_large = nums[0];
        int i;
        bool checker = false;
        for(i = 1; i < n; i++)
        {
            if(nums[i]<=pre_large)
            {
                if(checker)
                {
                    return false;
                }
                checker = true;
                if(i==1 || nums[i]>nums[i-2])
                {
                    pre_large = nums[i];
                }
            }
            else
            {
                pre_large = nums[i];
            }
        }
        return true;
    }
};
