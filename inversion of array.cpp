// link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    
    long long merge_inv(long long arr[],long long temp[], long long left,long long mid,long long right)
    {
        long long i,j,k;
        long long inv = 0;
        i = left;
        j = mid;
        k = left;
        while(i<=mid-1 and j<=right)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inv += mid-i;
            }
        }
        while(i <= mid-1)
        {
            temp[k++] = arr[i++];
        }
        while(j <= right)
        {
            temp[k++] = arr[j++];
        }
        for(int i = left;i<=right;i++)
        {
            arr[i] = temp[i];
        }
        return inv;
    }
    
    long long merge(long long arr[],long long temp[],long long left,long long right)
    {
        long long mid, inv = 0;
        
        if(right>left)
        {
            mid = (left+right)/2;
            inv += merge(arr,temp,left,mid);
            inv += merge(arr,temp,mid+1,right);
            inv += merge_inv(arr,temp,left,mid+1,right);
        }
        return inv;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long left = 0;
        int right = N-1;
        long long temp[N];
        return merge(arr,temp,left,right);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
