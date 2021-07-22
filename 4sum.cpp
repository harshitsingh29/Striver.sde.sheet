class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.size()<=3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-3; i++){
            for(int j = i+1; j < nums.size()-2; j++){
                int target1 = target - (nums[i] + nums[j]);
                int low = j+1;
                int high = nums.size()-1;
                while(low < high){
                    if(nums[low] + nums[high] == target1){
                        int temp1 = nums[low];
                        int temp2 = nums[high];
                        res.push_back({nums[i],nums[j],nums[low],nums[high]});
                        while(nums[low]==temp1 and low<high) low++;
                        while(nums[high]==temp2 and low<high) high--;
                    }
                    else if(nums[low] + nums[high] > target1){
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                } 
                while(j+1<nums.size() and nums[j+1]==nums[j]) j++;
            }
            while(i+1<nums.size() and nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};
