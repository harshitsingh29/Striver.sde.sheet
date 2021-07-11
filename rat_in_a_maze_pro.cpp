// link - 

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    void solve(int i,int j,vector<string>&ans,vector<vector<int>>&vis,vector<vector<int>>&m,int n,string move,int dx[],int dy[])
    {
        if(i==n-1 and j==n-1)
        {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for(int ind=0;ind<4;ind++)
        {
            int nexti = i + dx[ind];
            int nextj = j + dy[ind];
            if(nexti>=0 and nextj>=0 and nexti<=n-1 and nextj<=n-1 and !vis[nexti][nextj] and m[nexti][nextj]==1)
            {
                vis[i][j]=1;
                solve(nexti,nextj,ans,vis,m,n,move+dir[ind],dx,dy);
                vis[i][j]=0;
            }
        }
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1){
            solve(0,0,ans,vis,m,n,"",dx,dy);
        }
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
