// link - https://leetcode.com/problems/combination-sum/

class Solution {
public:
    
    void combination(int ind, int target, vector<int>&candidates, vector<int>&ds, vector<vector<int>>&ans,int n){
        if(ind==n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind] <= target)
        {
            ds.push_back(candidates[ind]);
            combination(ind,target-candidates[ind],candidates,ds,ans,n);
            ds.pop_back();
        }
        combination(ind+1,target,candidates,ds,ans,n);
}
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)     {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = candidates.size();
        combination(0,target,candidates,ds,ans,n);
        return ans;
    }
};
