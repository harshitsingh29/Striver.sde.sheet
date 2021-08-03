
// Binary Sol :- 
//

class Solution {
public:
    
    int min(int a,int b) {
        if(a > b){
            return b;
        }
        return a;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        if(strs.size() == 1) {
            return strs[0];
        }
        int l = 201;
        for(string it : strs) {
            l = min(l,it.length());
        }
        // cout<<l<<endl;
        int low = 1;
        int high = l;
        while(low <= high) {
            int middle = (high + low) / 2;
            // cout<<middle<<endl;
            if(iscommonprefix(strs,middle)) {
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }
        return strs[0].substr(0,(low + high) / 2);
    }
    
    bool iscommonprefix(vector<string>&strs, int& middle) {
        string pre = strs[0].substr(0,middle);
        // cout<<pre<<endl;
        for(int i = 1; i < strs.size(); i++) {
            // cout<<strs[i].substr(0,middle)<<endl;
            if(pre != strs[i].substr(0,middle)) {
                // cout<<pre<<" "<<strs[i].substr(0,middle)<<endl;
                return false;
            }
        }
        return true;
    }
};

// O(n^2) :-

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char c;
        string prefix = "";
        int j = 0;
        while(true) {
            for(int i = 0; i < strs.size(); i++) {
                if(j >= strs[i].size()) {
                    return prefix;
                }
                else if(i == 0) {
                    c = strs[i][j];
                }
                else{
                    if(c != strs[i][j]) {
                        return prefix;
                    }
                }
            }
            prefix += c;
            j++;
        }
        return prefix;
    }
};

