// link - https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        int n = s.length();
        func(0,n,res,part,s);
        return res;
    }
    
    void func(int ind, int n, vector<vector<string>> &res, vector<string> &part, string s)
    {
        if(index == n)
        {
            res.push_back(part);
            return;
        }
        for(int i = ind; i < n; i++)
        {
            if(ispalin(s, ind, i))
            {
                part.push_back(s.substr(ind, i - ind + 1));
                func(i + 1, n, res, part, s);
                part.pop_back();
            }
            
        }
    }
    
    bool ispalin(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
};
