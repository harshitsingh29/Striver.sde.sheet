// link - https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        if (nums.empty()) {
            return res;
        }
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n - 2; i++)
        {
            if((i==0 || (i > 0 and nums[i] != nums[i-1])) and nums[i]<=0)
            {
                int sum = 0 - nums[i];
                int low = i + 1;
                int high = n - 1;
                while(low<high)
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        res.push_back({nums[low],nums[high],nums[i]}); 
                        while(low < high and nums[low] == nums[low+1])
                            low++;
                        while(low < high and nums[high] == nums[high-1])
                            high--;
                        
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] > sum)
                        high--;
                    else
                        low++;
                }
            }
        }
        return res;  
    }
};
