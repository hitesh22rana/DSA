class Solution {
private:
    int expandFromMiddle(string s , int left , int right) {
        if(s.size() == 0 || left > right) return 0;
        
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
    
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int n = s.size();
        
        int start = 0;
        int end = 0;
        
        for(int i = 0 ; i<n ; i++) {
            int len1 = expandFromMiddle(s,i,i);
            int len2 = expandFromMiddle(s,i,i+1);
            int len = max(len1,len2);    
            
            if(len > end - start) {
                start = i - ((len - 1)>>1);
                end = i + (len>>1);
            }
            
        }
        return s.substr(start,end-start+1);
    }
};