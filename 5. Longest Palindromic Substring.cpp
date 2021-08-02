// link - 

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), count = 0;
        bool t[n][n];
        string res;
        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) {
                    t[i][j] = true;
                }
                else if (g == 1) {
                    t[i][j] = (s[i] == s[j]);
                }
                else if (s[i] == s[j] and t[i + 1][j - 1] == true) {
                    t[i][j] = true;
                }
                else {
                    t[i][j] = false;
                }
                if (t[i][j]) {
                    res = s.substr(i,g+1);
                }
            }
        }
        return res;
        
        
        int i = 0, l = 0, r = 0, lhold = 0, rhold = 0, n = s.size();
        while(i < n) {
            r = i;
            l = i;
            while(r < (n-1) and s[r] == s[r+1]) {
                r++;
            }
            i = r+1;
            while((l > 0) and (r < n - 1) and s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            if(r-l > rhold - lhold) {
                rhold = r;
                lhold = l;
            }
        }
        return s.substr(lhold,rhold-lhold+1);   
    }
};
