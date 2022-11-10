class Solution {
public:
    string removeDuplicates(string str) {
        string ans = "";
        int stptr = -1;
        
        for(char c : str) {
            
            if(stptr == -1 || str[stptr] != c) {
                stptr++;
                str[stptr] = c;
            }
            
            else {
                stptr--;
            }
        }
        
        for(int i = 0 ; i<=stptr ; i++) {
            ans += str[i];    
        }
        
        return ans;
    }
};