// link - https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    map<int,int>mp;
    int count = 0;
    int xorr = 0;
    for(int i = 0; i < A.size(); i++)
    {
        xorr^=A[i];
        if(xorr == B)
        {
            count++;
        }
        if(mp.find(xorr^B)!=mp.end())
        {
            count += mp[xorr^B];
        }
        mp[xorr]+=1;
    }
    return count;
}
