class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        int start = 0;
        int n = pattern.size();
        
        for(int i = 0 ; i<=n ; i++) {
            start++;
            if(pattern[i] == 'D') {
                string st = "";
                bool flag = false;
                
                for(; i<n ; i++) {
                    if(pattern[i] == 'I') {
                        st.push_back('0' + start);
                        flag = true;
                        break;
                    } else {
                        st.push_back('0' + start);
                    }
                    start++;
                }
                
                if(i == n) {
                    st.push_back('0' + start);
                    flag = true;
                }
                
                if(flag) {
                    reverse(st.begin(),st.end());
                }
                ans += st;
                
            } else {
                ans.push_back('0' + start);
            }
        }
        
        return ans;
    }
};