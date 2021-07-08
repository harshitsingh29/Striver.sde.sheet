// link - https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        int fact = 1;
        for(int i = 1; i < n; i++)
        {
            nums.push_back(i);
            fact *= i;
        }
        k--;
        string ans = "";
        nums.push_back(n);
        while(true)
        {
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + (k / fact));
            if(nums.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact /= nums.size();
        }
        return ans;
        
    }
};
