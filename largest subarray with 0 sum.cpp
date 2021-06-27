// link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

int maxLen(int arr[], int n)
{
    unordered_map<int,int>mp;
    int sum = 0;
    int max_len = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum += arr[i];
        if(arr[i]==0 and max_len == 0)
        {
            max_len = 1;
        }
        if(sum == 0)
        {
            max_len = i + 1;
        }
        if(mp.find(sum)!=mp.end())
        {
            max_len = max(max_len,i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return max_len;
}
