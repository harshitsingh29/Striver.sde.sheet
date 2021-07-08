// link - https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        func(0, n, ans, nums);
        return ans;
    }
    
    void func(int index, int size, vector<vector<int>> &ans, vector<int> &nums)
    {
        if(index == size)
        {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < size; i++)
        {
            swap(nums[index],nums[i]);
            func(index + 1, size, ans, nums);
            swap(nums[index],nums[i]);
        }
    }
};
