class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        int n = s.size()-1;
        
        for(int i = n ; i>=0 ; i--) {
            if(!st.empty()) {
                char c = st.top();
                if(c != s[i] && (tolower(c) == s[i] || toupper(c) == s[i])) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
                
            } else {
                st.push(s[i]);
            }
        }
        
        string ans;
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};