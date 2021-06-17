//https://leetcode.com/problems/merge-intervals/

vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>>mg;
        if(intervals.size()==1 || intervals.size()==0)
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        for(auto it : intervals)
        {
            if(it[0]<=temp[1])
            {
                temp[1] = max(it[1],temp[1]);
            }
            else
            {
                mg.push_back(temp);
                temp = it;
            }
        }
        mg.push_back(temp);
        return mg;
    }
