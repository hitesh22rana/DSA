class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() <= 1) return false;
        for(int i = 0 ; i<s.size() ; i++) {
            string str1 = s.substr(0,i+1);
            bool flag = true;
            int count = 0;
            for(int j = i+1 ; j<s.size() ; j+=str1.size()) {
                string str2 = s.substr(j,str1.size());
                if(str1 != str2) {
                    flag = false;
                    break;
                }
                
                count++;
                
            }
            if(flag && count) return true;
        }
        
        return false;
    }
};