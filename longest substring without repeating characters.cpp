// link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0 || n==1)
        {
            return n;
        }
        map<char,int>mp;
        int i = 0, j = 0, max_len = 1;
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            { 
                if(i>mp[s[j]])
                {
                    mp[s[j]] = j;
                    max_len = max(max_len,j-i+1);
                }
                else
                {
                    i = mp[s[j]]+1;
                    mp[s[j]] = j;
                }
            }
            else
            {
                mp[s[j]] = j;
                max_len = max(max_len,j-i+1);
            }
            j++;
            
        }
        return max_len;   
    }
};
