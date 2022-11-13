class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        
        int start = 0;
        int end = s.size();
        
        string str = "";
        
        while(start < end) {
            if(s[start] == ' ') {
                
                if(str != "" || str.size() != 0) {
                    st.push(str);
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
            st.push(str);
        }
        
        string ans = "";
        
        while(!st.empty()) {
            ans += st.top() + " ";
            st.pop();
        }
        
        ans.pop_back();
        
        return ans;
    }
};