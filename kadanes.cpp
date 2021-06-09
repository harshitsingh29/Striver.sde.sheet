** - https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
int maxSubarraySum(int arr[], int n){
        int maxsum = 0,maxt = 0;
        for(int i = 0;i<n;i++)
        {
            maxsum = maxsum + arr[i];
            if(maxsum>maxt)
            {
                maxt = maxsum;
            }
            if(maxsum < 0)
            {
                maxsum = 0;
            }
        }
        return maxt;
        
    }
