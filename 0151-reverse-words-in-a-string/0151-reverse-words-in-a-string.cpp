class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        int start = 0;
        int end = s.size();
        
        string str = "";
        
        while(start < end) {
            if(s[start] == ' ') {
                
                if(str != "" || str.size() != 0) {
                    ans = " " + str + ans;
                    str = "";
                }
                
                start++;
                continue;
            } else {
                str.push_back(s[start]);
                start++;
            }
            
        }
        
        if(str != "" || str.size() > 0) {
            ans = " " + str + ans;
        }


        return ans.substr(1);
    }
};