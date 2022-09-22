class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = s.size();

        string ans;
        string str;
        
        while(start < end) {
            if(s[start] == ' ') {
                reverse(str.begin(),str.end());
                ans += str;
                ans.push_back(' ');
                str.clear();
                start++;
                continue;
            }
            
            str.push_back(s[start++]);
        }
        
        reverse(str.begin(),str.end());
        ans += str;
        
        return ans;
    }
};