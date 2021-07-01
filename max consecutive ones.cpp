// link - https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, m = 0;
        for(auto i : nums)
        {
            if(i==1)
            {
                count++;
                m = max(m, count);
            }
            else
            {
                count = 0;
            }
        }
        return m;
    }
};
