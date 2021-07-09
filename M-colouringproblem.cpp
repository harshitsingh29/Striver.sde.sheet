// link - https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool issafe(int node, int colour[], bool graph[101][101], int n, int col){
    for(int k = 0; k < node; k++){
        if(k!=node and graph[k][node] == 1 and colour[k] == col){
            return false;
        }
    }
    return true;
}

bool solve(int node, bool graph[101][101], int m, int V,int colour[]){
    if(node == V) {
        return true;
    }
    for(int i = 1; i <= m; i++){
        if(issafe(node,colour,graph,V,i)){
            colour[node] = i;
            if(solve(node + 1, graph, m, V, colour)) return true;
            colour[node] = 0;
        }
    }
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{
    int colour[V] = {0};
    if(solve(0,graph,m,V,colour)) return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
