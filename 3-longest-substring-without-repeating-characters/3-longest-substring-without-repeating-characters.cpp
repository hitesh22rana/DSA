class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        if(st.size() == 0) {
            return 0;
        }
        
        int start = 0;
        int end = 0;
        int maxi = 0;
        int len = st.size();
        
        char ch;
        unordered_set<char> s;
        
        while(end < len) {
            ch = st[end];
            
            while(s.find(ch) != s.end()) {
                s.erase(st[start]);
                start++;
            }
            
            s.insert(ch);
            maxi = max(maxi , end - start+1);
            end++;
        }
        
        return maxi;
    }
};