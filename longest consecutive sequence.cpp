// link - https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0)
        {
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int j = 1,count = 1, m = 0;
        while(j<nums.size())
        {
            if(nums[j-1]+1==nums[j])
            {
                count++;
            }
            else if(nums[j]!=nums[j-1])
            {
                count = 1;
            }
            m = max(m,count);
            j++;
        }
        return m;
    }
};
