// link - 

//using stack

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        if(n == 0) {
            return s;
        }
        stack<string>st;
        string result;
        for(int i = 0; i < n; i++) {
            string word;
            if(s[i] == ' ') continue;
            while(s[i]!=' ' and i < n) {
                word += s[i];
                i++;
            }
            st.push(word);
        }
        while(!st.empty()) {
            result += st.top();
            st.pop();
            if(!st.empty()) {
                result+=' ';
            }
        }
        return result;
    }
};

// without stack

class Solution {
public:
    void reverse_word(string& s, int i, int j) {
        while(i < j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        int i = 0, j = 0;
        int word_cnt = 0;
        int size = s.size();
        while(true) {
            while(i < size && s[i] == ' ') {
                i++;
            }
            if(i == size) {
                break;
            }

            if(word_cnt) {
                s[j++] = ' ';
            }
            int start = j;
            while(i < size && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverse_word(s, start, j-1);
            // cout<<s<<endl;
            word_cnt++;
        }
        s.resize(j);
        reverse_word(s, 0, j-1);
        return s;
    }
};
