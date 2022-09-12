class Solution {
public:
    string reverseStr(string s, int k) {
        string ans;
        string rev;
        
        int i = 0;
        
        while(i < s.size()) {
            rev += s[i];
            i++;
            
            if(rev.size() == k) {
                reverse(rev.begin(),rev.end());
                ans += rev;
                rev.erase();

                int j = i+k;
                
                while(i < s.size() && i < j) {
                    ans.push_back(s[i]);
                    i++;
                }                
            }
        }
        
        if(rev.size() != k) {
            reverse(rev.begin(),rev.end());
            ans += rev;
        }
        
        return ans;
    }
};