// link - https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        int i,j,temp;
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                temp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = temp;
            }
        }
        for(i=0;i<n;i++)
        {
            reverse(m[i].begin(),m[i].end());
        }
    }
};
